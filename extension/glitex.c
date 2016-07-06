/*
 *   Experimental extension for SQLite implemented in Go
 *   Copyright (C) 2016  Milosz Piglas
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */ 
 
#include <sqlite3ext.h> 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../glitexbase.h"

SQLITE_EXTENSION_INIT1

#ifdef _WIN32
__declspec(dllexport)
#endif

void str_join(sqlite3_context* ctx, int argc, sqlite3_value** values)
{
  GoString input[argc-1];
  for (int i = 1; i < argc; i++)
  {
  	input[i-1].p = sqlite3_value_text(*(values + i));
    input[i-1].n = strlen(input[i-1].p);	
  }
  
  GoString sep = {sqlite3_value_text(*values), sqlite3_value_bytes(*values)};
  GoSlice slice = { &input[0], argc-1, argc-1 };
  struct CJoin_return result = CJoin(sep, slice);
  sqlite3_result_text(ctx, result.r0, result.r1, free);
}

void glitex_lic(sqlite3_context* ctx, int argc, sqlite3_value** values)
{
	GoString lic = License();
	sqlite3_result_text(ctx, lic.p, lic.n, NULL);
}

void glitex_ver(sqlite3_context* ctx, int argc, sqlite3_value** values)
{
	GoString ver = Version();
	sqlite3_result_text(ctx, ver.p, ver.n, NULL);
}


int sqlite3_glitex_init(
  sqlite3 *db, 
  char **pzErrMsg, 
  const sqlite3_api_routines *pApi
)
{
  int rc = SQLITE_OK;
  SQLITE_EXTENSION_INIT2(pApi);
  sqlite3_create_function_v2(db, "STR_JOIN", -1, SQLITE_UTF8 | SQLITE_DETERMINISTIC, 
  								NULL, str_join, NULL, NULL, NULL); 
  sqlite3_create_function_v2(db, "GLX_VERSION", 0, SQLITE_UTF8 | SQLITE_DETERMINISTIC, 
  								NULL, glitex_ver, NULL, NULL, NULL); 
  sqlite3_create_function_v2(db, "GLX_LICENSE", 0, SQLITE_UTF8 | SQLITE_DETERMINISTIC, 
  								NULL, glitex_lic, NULL, NULL, NULL); 

  return rc;
}
