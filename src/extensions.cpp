/*  smplayer, GUI front-end for mplayer.
    Copyright (C) 2006-2013 Ricardo Villalba <rvm@users.sourceforge.net>

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

#include "extensions.h"

ExtensionList::ExtensionList() : QStringList()
{
}

QString ExtensionList::forFilter() {
	QString s;
	for (int n=0; n < count(); n++) {
		s = s + "*." + at(n) + " ";
	}
	if (!s.isEmpty()) s = " (" + s + ")";
	return s;
}

QString ExtensionList::forRegExp() {
	QString s;
	for (int n=0; n < count(); n++) {
		if (!s.isEmpty()) s = s + "|";
		s = s + "^" + at(n) + "$";
	}
	return s;
}

Extensions::Extensions()
{
	_video << "avi" << "vfw" << "divx" 
           << "mpg" << "mpeg" << "m1v" << "m2v" << "mpv" << "dv" << "3gp"
           << "mov" << "mp4" << "m4v" << "mqv"
           << "dat" << "vcd"
           << "ogg" << "ogm" << "ogv" << "ogx"
           << "asf" << "wmv"
           << "bin" << "iso" << "vob"
           << "mkv" << "nsv" << "ram" << "flv"
           << "rm" << "swf"
           << "ts" << "rmvb" << "dvr-ms" << "m2t" << "m2ts" << "mts" << "rec" << "wtv"
           << "f4v" << "hdmov" << "webm" << "vp8"
           << "bik" << "smk" ;

	_audio << "mp3" << "ogg" << "oga" << "wav" << "wma" <<  "aac" << "ac3" << "dts" << "ra" << "ape" << "flac" << "thd" << "mka" << "m4a";

	_subtitles << "srt" << "sub" << "ssa" << "ass" << "idx" << "txt" << "smi"
               << "rt" << "utf" << "aqt";

	_playlist << "m3u" << "m3u8" << "pls";

	_multimedia = _video;
	for (int n = 0; n < _audio.count(); n++) {
		if (!_multimedia.contains(_audio[n])) _multimedia << _audio[n];
	}

	_all_playable << _multimedia << _playlist;
}

Extensions::~Extensions() {
}

