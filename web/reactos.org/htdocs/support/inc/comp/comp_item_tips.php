<?php
    /*
    RSDB - ReactOS Support Database
    Copyright (C) 2005-2006  Klemens Friedl <frik85@reactos.org>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
    */

/*
 *	ReactOS Support Database System - RSDB
 *	
 *	(c) by Klemens Friedl <frik85>
 *	
 *	2005 - 2006 
 */


	// To prevent hacking activity:
	if ( !defined('RSDB') )
	{
		die(" ");
	}


		$query_page = mysql_query("SELECT * 
									FROM `rsdb_item_comp` 
									WHERE `comp_visible` = '1'
									AND `comp_id` = " . $RSDB_SET_item . "
									ORDER BY `comp_name` ASC") ;
	
		$result_page = mysql_fetch_array($query_page);

		include('inc/tree/tree_item_menubar.php');
		
?>

	<h2>Tips and Tricks</h2>
	<p>[...]<br>
    </p>
