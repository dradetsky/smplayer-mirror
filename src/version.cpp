/*  smplayer, GUI front-end for mplayer.
    Copyright (C) 2007 Ricardo Villalba <rvm@escomposlinux.org>

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
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "version.h"

#define USE_SVN_VERSIONS 1

#if !USE_SVN_VERSIONS
#define VERSION "0.5.59"
#else
#define SVN_REVISION "$Revision$"
#include <QRegExp>
#endif

const char * smplayerVersion() {
#if USE_SVN_VERSIONS
	QRegExp rx("\\$Revision: (\\d+) \\$");
	QString v="Unknown";
	if (rx.indexIn(SVN_REVISION)!=-1) v = "SVN r"+rx.cap(1);
	return v.toLatin1().data();
#else
	return VERSION;
#endif
}
