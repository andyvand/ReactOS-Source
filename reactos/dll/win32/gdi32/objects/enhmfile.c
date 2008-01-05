#include "precomp.h"

#define NDEBUG
#include <debug.h>



/*
 * @unimplemented 
 */
HENHMETAFILE
WINAPI
CloseEnhMetaFile(
	HDC	hdc)
{
	UNIMPLEMENTED;
	return 0;
}

#if 0
/* Previous implementation in win32k */
HENHMETAFILE
STDCALL
NtGdiCloseEnhMetaFile(HDC  hDC)
{
  LPENHMETAHEADER emh;
  HANDLE hmf = 0;
  PDD_ENHMETAFILEOBJ phmf;
  HANDLE hMapping = 0;
  EMREOF emr;
  PDC Dc;

  IO_STATUS_BLOCK Iosb;
  NTSTATUS Status;



  Dc = DC_LockDc(hDC);
  if (Dc == NULL)
  {
      SetLastWin32Error(ERROR_INVALID_HANDLE);
      return NULL;
  }

  emr.emr.iType = EMR_EOF;
  emr.emr.nSize = sizeof(EMREOF);
  emr.nPalEntries = 0;
  emr.offPalEntries = 0;
  emr.nSizeLast = emr.emr.nSize;

  if(Dc->hFile)
  {
     Status = NtWriteFile(Dc->hFile, NULL, NULL, NULL, &Iosb, (PVOID)&emr, emr.emr.nSize, NULL, NULL);
     if (Status == STATUS_PENDING)
      {
          Status = NtWaitForSingleObject(Dc->hFile,FALSE,NULL);
          if (NT_SUCCESS(Status))
          {
              Status = Iosb.Status;
          }
      }

      if (NT_SUCCESS(Status))
      {
		  DWORD len = Dc->emh->nBytes + emr.emr.nSize;
		  /* always resize the buffer */
		  emh = EngAllocMem(FL_ZERO_MEMORY, len, 0);
		  if (emh != NULL)
	      {
              memcpy(emh,Dc->emh,Dc->emh->nBytes);
	          EngFreeMem(Dc->emh);
	          Dc->emh = emh;

			  memcpy(Dc->emh + Dc->emh->nBytes, &emr, emr.emr.nSize);
	      }
	      else
	      {
	          EngFreeMem(Dc->emh);
	          Dc->emh=NULL;
	      }

      }
      else
      {
          Dc->hFile = NULL;
		  DPRINT1("Write to EnhMetaFile fail\n");
      }
  }

  Dc->emh->nBytes += emr.emr.nSize;
  Dc->emh->nRecords++;

  if(Dc->emh->rclFrame.left > Dc->emh->rclFrame.right)
  {
     Dc->emh->rclFrame.left = Dc->emh->rclBounds.left * Dc->emh->szlMillimeters.cx * 100 / Dc->emh->szlDevice.cx;
     Dc->emh->rclFrame.top = Dc->emh->rclBounds.top * Dc->emh->szlMillimeters.cy * 100 / Dc->emh->szlDevice.cy;
     Dc->emh->rclFrame.right = Dc->emh->rclBounds.right * Dc->emh->szlMillimeters.cx * 100 / Dc->emh->szlDevice.cx;
     Dc->emh->rclFrame.bottom = Dc->emh->rclBounds.bottom * Dc->emh->szlMillimeters.cy * 100 / Dc->emh->szlDevice.cy;
  }

  if (Dc->hFile)  /* disk based metafile */
  {
	  FILE_POSITION_INFORMATION FilePosition;
	  LARGE_INTEGER Distance ;
	  IO_STATUS_BLOCK IoStatusBlock;

	  POBJECT_ATTRIBUTES ObjectAttributes = NULL;
      ACCESS_MASK DesiredAccess;
	  PLARGE_INTEGER SectionSize = NULL;
	  DWORD flProtect;
	  ULONG Attributes;
	  LARGE_INTEGER SectionOffset;
      ULONG ViewSize;
      ULONG Protect;
      LPVOID ViewBase;

	  Distance.u.LowPart = 0;
      Distance.u.HighPart = 0;
	  FilePosition.CurrentByteOffset.QuadPart = Distance.QuadPart;

	  DPRINT1("Trying write to metafile and map it\n");

	  Status = NtSetInformationFile(Dc->hFile, &IoStatusBlock, &FilePosition,
		                             sizeof(FILE_POSITION_INFORMATION), FilePositionInformation);

	 if (!NT_SUCCESS(Status))
     {
		 // SetLastErrorByStatus(Status);
         SetLastWin32Error(ERROR_INVALID_HANDLE);

		 NtClose( Dc->hFile );
		 DC_UnlockDc(Dc);
		 NtGdiDeleteObjectApp(hDC);

		 DPRINT1("NtSetInformationFile fail\n");
	     return hmf;
     }

	 if (FilePosition.CurrentByteOffset.u.LowPart != 0)
	 {
		 // SetLastErrorByStatus(Status);
		 SetLastWin32Error(ERROR_INVALID_HANDLE);

		 NtClose( Dc->hFile );
		 DC_UnlockDc(Dc);
		 NtGdiDeleteObjectApp(hDC);
		 DPRINT1("FilePosition.CurrentByteOffset.u.LowPart is not 0\n");
	     return hmf;
	 }

	 Status = NtWriteFile(Dc->hFile, NULL, NULL, NULL, &Iosb, (PVOID)&Dc->emh,  sizeof(*Dc->emh), NULL, NULL);
     if (Status == STATUS_PENDING)
     {
          Status = NtWaitForSingleObject(Dc->hFile,FALSE,NULL);
          if (NT_SUCCESS(Status))
          {
              Status = Iosb.Status;
          }
      }

      if (!NT_SUCCESS(Status))
      {
         NtClose( Dc->hFile );
		 DC_UnlockDc(Dc);
         NtGdiDeleteObjectApp(hDC);
		 DPRINT1("fail to write 0\n");
         return hmf;
      }

	  EngFreeMem(Dc->emh);

      /* create maping */
      DesiredAccess = STANDARD_RIGHTS_REQUIRED | SECTION_QUERY | SECTION_MAP_READ;
      Attributes = (PAGE_READONLY & (SEC_FILE | SEC_IMAGE | SEC_RESERVE | SEC_NOCACHE | SEC_COMMIT));
      flProtect = PAGE_READONLY ^ (PAGE_READONLY & (SEC_FILE | SEC_IMAGE | SEC_RESERVE | SEC_NOCACHE | SEC_COMMIT));

      if (!Attributes) Attributes = SEC_COMMIT;

      if (Dc->hFile == INVALID_HANDLE_VALUE)
      {
          Dc->hFile = NULL;
          if (!SectionSize)
          {
			 SetLastWin32Error(ERROR_INVALID_PARAMETER);
             hMapping = NULL;
			 DPRINT1("fail !SectionSize \n");
          }
      }
	  else
	  {
          Status = NtCreateSection(&hMapping, DesiredAccess, ObjectAttributes, SectionSize, flProtect, Attributes, Dc->hFile);
          if (!NT_SUCCESS(Status))
          {
          //SetLastErrorByStatus(Status);
		      SetLastWin32Error(ERROR_INVALID_HANDLE);
              hMapping =  NULL;
			  DPRINT1("fail NtCreateSection \n");
          }
	  }

      /* MapViewOfFile */
      SectionOffset.LowPart = 0;
      SectionOffset.HighPart = 0;
      ViewBase = NULL;
      ViewSize = 0;

      Protect = PAGE_READONLY;

      Status = ZwMapViewOfSection(&hMapping, NtCurrentProcess(), &ViewBase, 0,
		                          0, &SectionOffset, &ViewSize, ViewShare, 0, Protect);
      if (!NT_SUCCESS(Status))
      {
          //SetLastErrorByStatus(Status);
		  SetLastWin32Error(ERROR_INVALID_HANDLE);
          Dc->emh = NULL;
		  DPRINT1("fail ZwMapViewOfSection \n");
      }
	  else
      {
          Dc->emh = ViewBase;
	  }
      /* Close */
	  if (hMapping != NULL)
          NtClose( hMapping );
	  if (Dc->hFile != NULL)
          NtClose( Dc->hFile );
    }

  hmf = GDIOBJ_AllocObj(GdiHandleTable, GDI_OBJECT_TYPE_ENHMETAFILE);
  if (hmf != NULL)
  {
     phmf = GDIOBJ_LockObj(GdiHandleTable, hmf, GDI_OBJECT_TYPE_ENHMETAFILE);
	 if (phmf != NULL)
	 {
         if (Dc->hFile != NULL)
         {
             phmf->on_disk = TRUE;
	     }
         else
         {
	         phmf->on_disk = FALSE;
         }
		 GDIOBJ_UnlockObjByPtr(GdiHandleTable, phmf);
		 phmf->emh = Dc->emh;
	 }
  }

  Dc->emh = NULL;  /* So it won't be deleted */
  DC_UnlockDc(Dc);
  NtGdiDeleteObjectApp(hDC);
  return hmf;
}
#endif

#if 0 // Remove once new EnhMetaFile support is implemented.
HDC
WINAPI
CreateEnhMetaFileW(
    HDC           hDC,        /* [in] optional reference DC */
    LPCWSTR       filename,   /* [in] optional filename for disk metafiles */
    const RECT*   rect,       /* [in] optional bounding rectangle */
    LPCWSTR       description /* [in] optional description */
    )
{
    HDC mDC;
    PDC_ATTR Dc_Attr;
    PLDC pLDC;
    HANDLE hFile;
    PENHMETAFILE EmfDC;
    DWORD size = 0, length = 0;

    mDC = NtGdiCreateMetafileDC( hDC ); // Basically changes the handle from 1xxxx to 46xxxx.
    // If hDC == NULL, works just like createdc in win32k.

    if ( !GdiGetHandleUserData((HGDIOBJ) mDC, GDI_OBJECT_TYPE_DC, (PVOID) &Dc_Attr))
    {
      SetLastError (ERROR_INVALID_PARAMETER);
      return NULL; // need to delete the handle?
    }

    pLDC = LocalAlloc(LMEM_ZEROINIT, sizeof(LDC));

    Dc_Attr->pvLDC = pLDC;
    pLDC->hDC = mDC;
    pLDC->iType = LDC_EMFDC


    if (description)
    { /* App name\0Title\0\0 */
        length = lstrlenW(description);
        length += lstrlenW(description + length + 1);
        length += 3;
        length *= 2;
    }

    size = sizeof(ENHMETAFILE) + (length + 3) / 4 * 4;

    //Allocate ENHMETAFILE structure
    EmfDC = LocalAlloc(LMEM_ZEROINIT, sizeof(ENHMETAFILE));
    pLDC->pvEmfDC = EmfDC;

    EmfDC->handles_size = HANDLE_LIST_INC;
    EmfDC->cur_handles = 1;

    EmfDC->horzres = GetDeviceCaps(mDC, HORZRES);
    EmfDC->vertres = GetDeviceCaps(mDC, VERTRES);
    EmfDC->logpixelsx = GetDeviceCaps(mDC, LOGPIXELSX);
    EmfDC->logpixelsy = GetDeviceCaps(mDC, LOGPIXELSY);
    EmfDC->horzsize = GetDeviceCaps(mDC, HORZSIZE);
    EmfDC->vertsize = GetDeviceCaps(mDC, VERTSIZE);
    EmfDC->bitspixel = GetDeviceCaps(mDC, BITSPIXEL);
    EmfDC->textcaps = GetDeviceCaps(mDC, TEXTCAPS);
    EmfDC->rastercaps = GetDeviceCaps(mDC, RASTERCAPS);
    EmfDC->technology = GetDeviceCaps(mDC, TECHNOLOGY);
    EmfDC->planes = GetDeviceCaps(mDC, PLANES);

    EmfDC->emf = LocalAlloc(LMEM_ZEROINIT, size);

    EmfDC->emf->iType = EMR_HEADER;
    EmfDC->emf->nSize = size;

    EmfDC->emf->rclBounds.left = EmfDC->emf->rclBounds.top = 0;
    EmfDC->emf->rclBounds.right = EmfDC->emf->rclBounds.bottom = -1;

    if(rect)
    {
        EmfDC->emf->rclFrame.left   = rect->left;
        EmfDC->emf->rclFrame.top    = rect->top;
        EmfDC->emf->rclFrame.right  = rect->right;
        EmfDC->emf->rclFrame.bottom = rect->bottom;
    }
    else
    {  /* Set this to {0,0 - -1,-1} and update it at the end */
        EmfDC->emf->rclFrame.left = EmfDC->emf->rclFrame.top = 0;
        EmfDC->emf->rclFrame.right = EmfDC->emf->rclFrame.bottom = -1;
    }

    EmfDC->emf->dSignature = ENHMETA_SIGNATURE;
    EmfDC->emf->nVersion = 0x10000;
    EmfDC->emf->nBytes = pLDC->pvEmfDC->nSize;
    EmfDC->emf->nRecords = 1;
    EmfDC->emf->nHandles = 1;

    EmfDC->emf->sReserved = 0; /* According to docs, this is reserved and must be 0 */
    EmfDC->emf->nDescription = length / 2;

    EmfDC->emf->offDescription = length ? sizeof(ENHMETAHEADER) : 0;

    EmfDC->emf->nPalEntries = 0; /* I guess this should start at 0 */

    /* Size in pixels */
    EmfDC->emf->szlDevice.cx = EmfDC->horzres;
    EmfDC->emf->szlDevice.cy = EmfDC->vertres;

    /* Size in millimeters */
    EmfDC->emf->szlMillimeters.cx = EmfDC->horzsize;
    EmfDC->emf->szlMillimeters.cy = EmfDC->vertsize;

    /* Size in micrometers */
    EmfDC->emf->szlMicrometers.cx = EmfDC->horzsize * 1000;
    EmfDC->emf->szlMicrometers.cy = EmfDC->vertsize * 1000;

    RtlCopyMemory((char *)EmfDC->emf + sizeof(ENHMETAHEADER), description, length);

    if (filename)  /* disk based metafile */
    {
        if ((hFile = CreateFileW(filename, GENERIC_WRITE | GENERIC_READ, 0,
				 NULL, CREATE_ALWAYS, 0, 0)) == INVALID_HANDLE_VALUE)
        {
            EMFDRV_DeleteDC( EmfDC );
            return NULL;
        }
        if (!WriteFile( hFile, (LPSTR)EmfDC->emf, size, NULL, NULL ))
        {
            EMFDRV_DeleteDC( EmfDC );
            return NULL;
	}
	EmfDC.hFile = hFile;
	EmfDC.iType = METAFILE_DISK;
    }
    else
        EmfDC.iType = METAFILE_MEMORY;

    return mDC;
}
#endif


/*
 * @unimplemented
 */
HENHMETAFILE
WINAPI
CopyEnhMetaFileA(
	HENHMETAFILE	hemfSrc,
	LPCSTR		lpszFile)
{
  NTSTATUS Status;
  LPWSTR lpszFileW;
  HENHMETAFILE rc = 0;

  Status = HEAP_strdupA2W ( &lpszFileW, lpszFile );
  if (!NT_SUCCESS (Status))
    SetLastError (RtlNtStatusToDosError(Status));
  else
    {
      rc = NULL;

      HEAP_free ( lpszFileW );
    }
  return rc;
}


/*
 * @unimplemented
 */
HDC
WINAPI
CreateEnhMetaFileA(
	HDC		hdcRef,
	LPCSTR		lpFileName,
	CONST RECT	*lpRect,
	LPCSTR		lpDescription)
{
  NTSTATUS Status;
  LPWSTR lpFileNameW, lpDescriptionW;
  HDC rc = 0;

  lpFileNameW = NULL;
  if (lpFileName != NULL)
  {
	 Status = HEAP_strdupA2W ( &lpFileNameW, lpFileName );
     if (!NT_SUCCESS (Status))
         SetLastError (RtlNtStatusToDosError(Status));

	 return rc;
  }

  lpDescriptionW = NULL;
  if (lpDescription != NULL)
  {
     Status = HEAP_strdupA2W ( &lpDescriptionW, lpDescription );
      if (!NT_SUCCESS (Status))
	      SetLastError (RtlNtStatusToDosError(Status));

	  return rc;
  }

  rc = NULL;

  if (lpDescriptionW != NULL)
      HEAP_free ( lpDescriptionW );

  if (lpFileNameW != NULL)
       HEAP_free ( lpFileNameW );

  return rc;
}




/*
 * @unimplemented
 */
HENHMETAFILE
WINAPI
GetEnhMetaFileA(
	LPCSTR	lpszMetaFile)
{
  NTSTATUS Status;
  LPWSTR lpszMetaFileW;
  HENHMETAFILE rc = 0;

  Status = HEAP_strdupA2W ( &lpszMetaFileW, lpszMetaFile );
  if (!NT_SUCCESS (Status))
    SetLastError (RtlNtStatusToDosError(Status));
  else
  {
    rc = NULL;

    HEAP_free ( lpszMetaFileW );
  }

  return rc;
}


/*
 * @unimplemented
 */
UINT
WINAPI
GetEnhMetaFileDescriptionA(
	HENHMETAFILE	hemf,
	UINT		cchBuffer,
	LPSTR		lpszDescription)
{
  NTSTATUS Status;
  LPWSTR lpszDescriptionW;

  if ( lpszDescription && cchBuffer )
    {
      lpszDescriptionW = (LPWSTR)HEAP_alloc ( cchBuffer*sizeof(WCHAR) );
      if ( !lpszDescriptionW )
	{
	  SetLastError (RtlNtStatusToDosError(STATUS_NO_MEMORY));
	  return 0;
	}
    }
  else
    lpszDescriptionW = NULL;

  if ( lpszDescription && cchBuffer )
    {
      Status = RtlUnicodeToMultiByteN ( lpszDescription,
	                                cchBuffer,
	                                NULL,
	                                lpszDescriptionW,
	                                cchBuffer );
      HEAP_free ( lpszDescriptionW );
      if ( !NT_SUCCESS(Status) )
	{
	  SetLastError (RtlNtStatusToDosError(Status));
	  return 0;
	}
    }

  return 0;
}



/* Unimplemented functions  */

HENHMETAFILE
WINAPI
CopyEnhMetaFileW(
	HENHMETAFILE	hemfSrc,
	LPCWSTR		lpszFile)
{
  UNIMPLEMENTED;
  return 0;
}


HENHMETAFILE
WINAPI
GetEnhMetaFileW(
	LPCWSTR	lpszMetaFile)
{
  UNIMPLEMENTED;
  return 0;
}


UINT
WINAPI
GetEnhMetaFileDescriptionW(
	HENHMETAFILE	hemf,
	UINT		cchBuffer,
	LPWSTR		lpszDescription)
{
  UNIMPLEMENTED;
  return 0;
}


HDC
WINAPI
CreateEnhMetaFileW(
	HDC  hdcRef,
	LPCWSTR  lpFileName,
	LPCRECT  lpRect,
	LPCWSTR  lpDescription)
{
  UNIMPLEMENTED;
  return 0;
}
