/***************************************************************************
 *   Copyright (C) 2012 Azamat H. Hackimov                                 *
 *   azamat.hackimov@gmail.com                                             *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <pppd/pathnames.h>
#include <pppd/patchlevel.h>
#include <stdio.h>

// gcc -DPLUGIN -DDESTDIR="\"/usr\"" -o ppp_ver_check ppp_ver_check.c

int main(void) {
	printf("%s", _PATH_PLUGIN);
	return 0;
}

