/*******************************************************************************
*                                                                              *
* highlightData.h -- Nirvana Editor Highlight Data Header File                 *
*                                                                              *
* Copyright 2003 The NEdit Developers                                          *
*                                                                              *
* This is free software; you can redistribute it and/or modify it under the    *
* terms of the GNU General Public License as published by the Free Software    *
* Foundation; either version 2 of the License, or (at your option) any later   *
* version. In addition, you may distribute versions of this program linked to  *
* Motif or Open Motif. See README for details.                                 *
*                                                                              *
* This software is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or        *
* FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for    *
* more details.                                                                *
*                                                                              *
* You should have received a copy of the GNU General Public License along with *
* software; if not, write to the Free Software Foundation, Inc., 59 Temple     *
* Place, Suite 330, Boston, MA  02111-1307 USA                                 *
*                                                                              *
* Nirvana Text Editor                                                          *
* July 31, 2001                                                                *
*                                                                              *
*******************************************************************************/

#ifndef HIGHLIGHTDATA_H_
#define HIGHLIGHTDATA_H_

#include "highlight.h"
#include "nedit.h"
#include <string>

#include <X11/Intrinsic.h>
#include <X11/Xlib.h>

XFontStruct *FontOfNamedStyle(WindowInfo *window, const char *styleName);
char *WriteStylesString(void);
char *WriteHighlightString(void);
const char *BgColorOfNamedStyle(const char *styleName);
const char *ColorOfNamedStyle(const char *styleName);
int FontOfNamedStyleIsBold(const char *styleName);
int FontOfNamedStyleIsItalic(const char *styleName);
int IndexOfNamedStyle(const char *styleName);
int LMHasHighlightPatterns(const char *languageMode);
int LoadHighlightString(char *inString, int convertOld);
int LoadStylesString(const char *inString);
int NamedStyleExists(const char *styleName);
patternSet *FindPatternSet(const char *langModeName);
void EditHighlightPatterns(WindowInfo *window);
void EditHighlightStyles(const char *initialStyle);
void RenameHighlightPattern(const char *oldName, const char *newName);
void UpdateLanguageModeMenu(void);

#endif
