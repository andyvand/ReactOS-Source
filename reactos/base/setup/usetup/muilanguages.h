#ifndef LANG_MUI_LANGUAGES_H__
#define LANG_MUI_LANGUAGES_H__

#include "lang/bg-BG.h"
#include "lang/cs-CZ.h"
#include "lang/en-US.h"
#include "lang/de-DE.h"
#include "lang/el-GR.h"
#include "lang/es-ES.h"
#include "lang/fr-FR.h"
#include "lang/it-IT.h"
#include "lang/pl-PL.h"
#include "lang/ru-RU.h"
#include "lang/sk-SK.h"
#include "lang/sv-SE.h"
#include "lang/uk-UA.h"
#include "lang/lt-LT.h"

const MUI_LANGUAGE LanguageList[] =
{
  /* Lang ID,   ANSI CP, OEM CP, MAC CP,   Language Name,                   page strgs,error strings,    other strings, fonts,     kb layouts */
  {L"0000041C", L"1250", L"852", L"10029", L"Albanian",                     enUSPages, enUSErrorEntries, enUSStrings, CP1250Fonts, enUSLayouts },
  {L"00000401", L"1256", L"720", L"10004", L"Arabic (Saudi Arabia)",        enUSPages, enUSErrorEntries, enUSStrings, CP1256Fonts, enUSLayouts },
  {L"00000801", L"1256", L"720", L"10004", L"Arabic (Iraq)",                enUSPages, enUSErrorEntries, enUSStrings, CP1256Fonts, enUSLayouts },
  {L"00000C01", L"1256", L"720", L"10004", L"Arabic (Egypt)",               enUSPages, enUSErrorEntries, enUSStrings, CP1256Fonts, enUSLayouts },
  {L"00001001", L"1256", L"720", L"10004", L"Arabic (Libya)",               enUSPages, enUSErrorEntries, enUSStrings, CP1256Fonts, enUSLayouts },
  {L"00001401", L"1256", L"720", L"10004", L"Arabic (Algeria)",             enUSPages, enUSErrorEntries, enUSStrings, CP1256Fonts, enUSLayouts },
  {L"0000042B", L"0",    L"1",   L"2",     L"Armenian Eastern",             enUSPages, enUSErrorEntries, enUSStrings, UnicodeFonts,enUSLayouts },
  {L"0000082C", L"1251", L"866", L"10007", L"Azeri (Cyrillic)",             enUSPages, enUSErrorEntries, enUSStrings, CP1251Fonts, enUSLayouts },
  {L"0000042C", L"1254", L"857", L"10081", L"Azeri (Latin)",                enUSPages, enUSErrorEntries, enUSStrings, CP1254Fonts, enUSLayouts },
  {L"00000423", L"1251", L"866", L"10007", L"Belarusian",                   enUSPages, enUSErrorEntries, enUSStrings, CP1251Fonts, enUSLayouts },
  {L"00000813", L"1252", L"850", L"10000", L"Belgian (Dutch)",              enUSPages, enUSErrorEntries, enUSStrings, CP1252Fonts, enUSLayouts },
  {L"0000080C", L"1252", L"850", L"10000", L"Belgian (French)",             enUSPages, enUSErrorEntries, enUSStrings, CP1252Fonts, enUSLayouts },
  {L"00000416", L"1252", L"850", L"10000", L"Brazilian",                    enUSPages, enUSErrorEntries, enUSStrings, CP1252Fonts, enUSLayouts },
  {L"00000402", L"1251", L"866", L"10007", L"Bulgarian",                    bgBGPages, bgBGErrorEntries, bgBGStrings, CP1251Fonts, bgBGLayouts },
  {L"00000455", L"0",    L"1",   L"2",     L"Burmese",                      enUSPages, enUSErrorEntries, enUSStrings, UnicodeFonts,enUSLayouts },
  {L"00000C0C", L"1252", L"850", L"10000", L"Canadian (French)",            enUSPages, enUSErrorEntries, enUSStrings, CP1252Fonts, enUSLayouts },
  {L"00000403", L"1252", L"850", L"10000", L"Catalan",                      enUSPages, enUSErrorEntries, enUSStrings, CP1252Fonts, enUSLayouts },
  {L"00000404", L"950",  L"950", L"10008", L"Chinese (Taiwan)",             enUSPages, enUSErrorEntries, enUSStrings, CP950Fonts,  enUSLayouts },
  {L"00000804", L"936",  L"936", L"10008", L"Chinese (PRC)",                enUSPages, enUSErrorEntries, enUSStrings, CP936Fonts,  enUSLayouts },
  {L"00000C04", L"950",  L"950", L"10008", L"Chinese (Hong Kong S.A.R.)",   enUSPages, enUSErrorEntries, enUSStrings, CP950Fonts,  enUSLayouts },
  {L"00001004", L"936",  L"936", L"10008", L"Chinese (Singapore)",          enUSPages, enUSErrorEntries, enUSStrings, CP936Fonts,  enUSLayouts },
  {L"00000405", L"1250", L"852", L"10029", L"Czech",                        csCZPages, csCZErrorEntries, csCZStrings, CP1250Fonts, csCZLayouts },
  {L"00000406", L"1252", L"850", L"10000", L"Danish",                       enUSPages, enUSErrorEntries, enUSStrings, CP1252Fonts, enUSLayouts },
  {L"00000413", L"1252", L"850", L"10000", L"Dutch",                        enUSPages, enUSErrorEntries, enUSStrings, CP1252Fonts, enUSLayouts },
  {L"00000409", L"1252", L"437", L"10000", L"English (United States)",      enUSPages, enUSErrorEntries, enUSStrings, CP1252Fonts, enUSLayouts },
  {L"00000809", L"1252", L"850", L"10000", L"English (United Kingdom)",     enUSPages, enUSErrorEntries, enUSStrings, CP1252Fonts, enUSLayouts },
  {L"00000C09", L"1252", L"850", L"10000", L"English (Australia)",          enUSPages, enUSErrorEntries, enUSStrings, CP1252Fonts, enUSLayouts },
  {L"00001009", L"1252", L"850", L"10000", L"English (Canada)",             enUSPages, enUSErrorEntries, enUSStrings, CP1252Fonts, enUSLayouts },
  {L"00001409", L"1252", L"850", L"10000", L"English (New Zealand)",        enUSPages, enUSErrorEntries, enUSStrings, CP1252Fonts, enUSLayouts },
  {L"00001809", L"1252", L"850", L"10000", L"English (Ireland)",            enUSPages, enUSErrorEntries, enUSStrings, CP1252Fonts, enUSLayouts },
  {L"00001C09", L"1252", L"437", L"10000", L"English (South Africa)",       enUSPages, enUSErrorEntries, enUSStrings, CP1252Fonts, enUSLayouts },
  {L"00002009", L"1252", L"850", L"10000", L"English (Jamaica)",            enUSPages, enUSErrorEntries, enUSStrings, CP1252Fonts, enUSLayouts },
  {L"00002409", L"1252", L"850", L"10000", L"English (Caribbean)",          enUSPages, enUSErrorEntries, enUSStrings, CP1252Fonts, enUSLayouts },
  {L"00002809", L"1252", L"850", L"10000", L"English (Belize)",             enUSPages, enUSErrorEntries, enUSStrings, CP1252Fonts, enUSLayouts },
  {L"00002C09", L"1252", L"850", L"10000", L"English (Trinidad)",           enUSPages, enUSErrorEntries, enUSStrings, CP1252Fonts, enUSLayouts },
  {L"00003009", L"1252", L"437", L"10000", L"English (Zimbabwe)",           enUSPages, enUSErrorEntries, enUSStrings, CP1252Fonts, enUSLayouts },
  {L"00003409", L"1252", L"437", L"10000", L"English (Philippines)",        enUSPages, enUSErrorEntries, enUSStrings, CP1252Fonts, enUSLayouts },
  {L"00000425", L"1257", L"775", L"10029", L"Estonian",                     enUSPages, enUSErrorEntries, enUSStrings, CP1257Fonts, enUSLayouts },
  {L"0000040B", L"1252", L"850", L"10000", L"Finnish",                      enUSPages, enUSErrorEntries, enUSStrings, CP1252Fonts, enUSLayouts },
  {L"0000040C", L"1252", L"850", L"10000", L"French",                       frFRPages, frFRErrorEntries, frFRStrings, CP1252Fonts, frFRLayouts },
  {L"00000437", L"0",    L"1",   L"2",     L"Georgian",                     enUSPages, enUSErrorEntries, enUSStrings, UnicodeFonts,enUSLayouts },
  {L"00000407", L"1252", L"850", L"10000", L"German (Germany)",             deDEPages, deDEErrorEntries, deDEStrings, CP1252Fonts, deDELayouts },
  {L"00000408", L"1253", L"737", L"10006", L"Greek",                        elGRPages, elGRErrorEntries, elGRStrings, CP1253Fonts, elGRLayouts },
  {L"0000040D", L"1255", L"862", L"10005", L"Hebrew",                       enUSPages, enUSErrorEntries, enUSStrings, CP1255Fonts, enUSLayouts },
  {L"0000040E", L"1250", L"852", L"10029", L"Hungarian",                    enUSPages, enUSErrorEntries, enUSStrings, CP1250Fonts, enUSLayouts },
  {L"0000040F", L"1252", L"850", L"10079", L"Icelandic",                    enUSPages, enUSErrorEntries, enUSStrings, CP1252Fonts, enUSLayouts },
  {L"00000410", L"1252", L"850", L"10000", L"Italian (Italy)",              itITPages, itITErrorEntries, itITStrings, CP1252Fonts, itITLayouts },
  {L"00000411", L"932",  L"932", L"10001", L"Japanese",                     enUSPages, enUSErrorEntries, enUSStrings, CP932Fonts,  enUSLayouts },
  {L"0000043F", L"1251", L"866", L"10007", L"Kazakh",                       enUSPages, enUSErrorEntries, enUSStrings, CP1251Fonts, enUSLayouts },
  {L"00000412", L"949",  L"949", L"10003", L"Korean",                       enUSPages, enUSErrorEntries, enUSStrings, CP949Fonts,  enUSLayouts },
  {L"00000426", L"1257", L"775", L"10029", L"Latvian",                      enUSPages, enUSErrorEntries, enUSStrings, CP1257Fonts, enUSLayouts },
  {L"00000427", L"1257", L"775", L"10029", L"Lithuanian",                   ltLTPages, ltLTErrorEntries, ltLTStrings, CP1257Fonts, ltLTLayouts },
  {L"0000042F", L"1251", L"866", L"10007", L"Macedonian",                   enUSPages, enUSErrorEntries, enUSStrings, CP1251Fonts, enUSLayouts },
  {L"00000414", L"1252", L"850", L"10000", L"Norwegian",                    enUSPages, enUSErrorEntries, enUSStrings, CP1252Fonts, enUSLayouts },
  {L"00000418", L"1250", L"852", L"10029", L"Romanian",                     enUSPages, enUSErrorEntries, enUSStrings, CP1250Fonts, enUSLayouts },
  {L"00000419", L"1251", L"866", L"10007", L"Russkij",                      ruRUPages, ruRUErrorEntries, ruRUStrings, CP1251Fonts, ruRULayouts },
  {L"00000415", L"1250", L"852", L"10029", L"Polski",                       plPLPages, plPLErrorEntries, plPLStrings, CP1250Fonts, plPLLayouts },
  {L"00000816", L"1252", L"850", L"10000", L"Portuguese",                   enUSPages, enUSErrorEntries, enUSStrings, CP1252Fonts, enUSLayouts },
  {L"00000C1A", L"1251", L"855", L"10007", L"Serbian (Cyrillic)",           enUSPages, enUSErrorEntries, enUSStrings, CP1251Fonts, enUSLayouts },
  {L"0000081A", L"1250", L"852", L"10029", L"Serbian (Latin)",              enUSPages, enUSErrorEntries, enUSStrings, CP1250Fonts, enUSLayouts },
  {L"0000041B", L"1250", L"852", L"10029", L"Slovak",                       skSKPages, skSKErrorEntries, skSKStrings, CP1250Fonts, skSKLayouts },
  {L"0000040A", L"1252", L"850", L"10000", L"Spanish (Traditional Sort)",   esESPages, esESErrorEntries, esESStrings, CP1252Fonts, esESLayouts },
  {L"0000080A", L"1252", L"850", L"10000", L"Spanish (Mexico)",             esESPages, esESErrorEntries, esESStrings, CP1252Fonts, enUSLayouts },
  {L"00000C0A", L"1252", L"850", L"10000", L"Spanish (International Sort)", esESPages, esESErrorEntries, esESStrings, CP1252Fonts, enUSLayouts },
  {L"0000100A", L"1252", L"850", L"10000", L"Spanish (Guatemala)",          esESPages, esESErrorEntries, esESStrings, CP1252Fonts, enUSLayouts },
  {L"0000140A", L"1252", L"850", L"10000", L"Spanish (Costa Rica)",         esESPages, esESErrorEntries, esESStrings, CP1252Fonts, enUSLayouts },
  {L"0000180A", L"1252", L"850", L"10000", L"Spanish (Panama)",             esESPages, esESErrorEntries, esESStrings, CP1252Fonts, enUSLayouts },
  {L"00001C0A", L"1252", L"850", L"10000", L"Spanish (Dominican Republic)", esESPages, esESErrorEntries, esESStrings, CP1252Fonts, enUSLayouts },
  {L"0000200A", L"1252", L"850", L"10000", L"Spanish (Venezuela)",          esESPages, esESErrorEntries, esESStrings, CP1252Fonts, enUSLayouts },
  {L"0000240A", L"1252", L"850", L"10000", L"Spanish (Colombia)",           esESPages, esESErrorEntries, esESStrings, CP1252Fonts, enUSLayouts },
  {L"0000280A", L"1252", L"850", L"10000", L"Spanish (Peru)",               esESPages, esESErrorEntries, esESStrings, CP1252Fonts, enUSLayouts },
  {L"00002C0A", L"1252", L"850", L"10000", L"Spanish (Argentina)",          esESPages, esESErrorEntries, esESStrings, CP1252Fonts, enUSLayouts },
  {L"0000300A", L"1252", L"850", L"10000", L"Spanish (Ecuador)",            esESPages, esESErrorEntries, esESStrings, CP1252Fonts, enUSLayouts },
  {L"0000340A", L"1252", L"850", L"10000", L"Spanish (Chile)",              esESPages, esESErrorEntries, esESStrings, CP1252Fonts, enUSLayouts },
  {L"0000380A", L"1252", L"850", L"10000", L"Spanish (Uruguay)",            esESPages, esESErrorEntries, esESStrings, CP1252Fonts, enUSLayouts },
  {L"00003C0A", L"1252", L"850", L"10000", L"Spanish (Paraguay)",           esESPages, esESErrorEntries, esESStrings, CP1252Fonts, enUSLayouts },
  {L"0000400A", L"1252", L"850", L"10000", L"Spanish (Bolivia)",            esESPages, esESErrorEntries, esESStrings, CP1252Fonts, enUSLayouts },
  {L"0000440A", L"1252", L"850", L"10000", L"Spanish (El Salvador)",        esESPages, esESErrorEntries, esESStrings, CP1252Fonts, enUSLayouts },
  {L"0000480A", L"1252", L"850", L"10000", L"Spanish (Honduras)",           esESPages, esESErrorEntries, esESStrings, CP1252Fonts, enUSLayouts },
  {L"00004C0A", L"1252", L"850", L"10000", L"Spanish (Nicaragua)",          esESPages, esESErrorEntries, esESStrings, CP1252Fonts, enUSLayouts },
  {L"0000500A", L"1252", L"850", L"10000", L"Spanish (Puerto Rico)",        esESPages, esESErrorEntries, esESStrings, CP1252Fonts, enUSLayouts },
  {L"00000807", L"1252", L"850", L"10000", L"Swiss (German)",               enUSPages, enUSErrorEntries, enUSStrings, CP1252Fonts, enUSLayouts },
  {L"0000041D", L"1252", L"850", L"10000", L"Swedish",                      svSEPages, svSEErrorEntries, svSEStrings, CP1252Fonts, svSELayouts },
  {L"00000444", L"1251", L"866", L"10007", L"Tatar",                        enUSPages, enUSErrorEntries, enUSStrings, CP1251Fonts, enUSLayouts },
  {L"0000041E", L"874",  L"874", L"10021", L"Thai",                         enUSPages, enUSErrorEntries, enUSStrings, CP874Fonts,  enUSLayouts },
  {L"0000041F", L"1254", L"857", L"10081", L"Turkish",                      enUSPages, enUSErrorEntries, enUSStrings, CP1254Fonts, enUSLayouts },
  {L"00000422", L"1251", L"866", L"10017", L"Ukrainian",                    ukUAPages, ukUAErrorEntries, ukUAStrings, CP1251Fonts, ukUALayouts },
  {L"00000843", L"1251", L"866", L"10007", L"Uzbek",                        enUSPages, enUSErrorEntries, enUSStrings, CP1251Fonts, enUSLayouts },
  {L"0000042A", L"1258", L"1258",L"10000", L"Vietnamese",                   enUSPages, enUSErrorEntries, enUSStrings, CP1258Fonts, enUSLayouts },
  {L"00000435", L"1252", L"850", L"10000", L"Zulu",                         enUSPages, enUSErrorEntries, enUSStrings, CP1252Fonts, enUSLayouts },
  {NULL, NULL, NULL, NULL, NULL, NULL}
};

#endif
