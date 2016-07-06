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

#include <stdio.h>
#include <stdlib.h>
#include "../glitexbase.h"

int main() 
{
    GoString inputArray[3];
    
    inputArray[0].p = "xyz";
    inputArray[0].n = 3;
    
    inputArray[1].p = "EEEE";
    inputArray[1].n = 4;
    
    inputArray[2].p = "333333";
    inputArray[2].n = 6;
    
    GoString sep = {";", 1};
    GoSlice slice = { &inputArray[0], 3, 3 };
    struct CJoin_return result = CJoin(sep, slice);
    printf("%s\n", result.r0);
    free(result.r0);
    
    GoString lic = License();
    printf("licencse %s\n", lic.p);
    
    GoString ver = Version();
    printf("version %s\n", ver.p);
    
}
