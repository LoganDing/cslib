#ifndef String_H_LOADED
#define String_H_LOADED
// [
// $        String.h
// 
// Copyright 2011 Chris Sanchez
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.
// ====================================================================
//
// Copyright (c) 1998-2001 Chris Sanchez. All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer. 
// 
// 
// THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESSED OR IMPLIED
// WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED.  IN NO EVENT SHALL CHRIS SANCHEZ OR
// ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
// USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
// OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
// SUCH DAMAGE.
// ====================================================================
// 
// This software consists of voluntary contributions made by Chris Sanchez. 
// Portions of other open source software were used in the creation of this
// software. Header files for work based on other source bears the 
// orininator copyright.
//
//         Author: Chris Sanchez
// 
//         RCS:
//                 $Revision: 2.1 $
//                 $Author: sanchezc $
//                 $Date: 2002/09/26 17:19:31 $
// ?
//         Contents: String class
//
//         Purpose:
//
//         Usage Notes:
//
//                 
// ?
// !        Changes History
//     $Header: /cvs/common/cslib/h/lang/String.h,v 2.1 2002/09/26 17:19:31 sanchezc Exp $
//         
// ]

#include <cslib.h>

#include <string>

#ifdef UNICODE
    using std::wstring;
    #define String wstring
    #if defined(_WINDOWS) || defined(WIN32)
        #define NTEXT(x) __TEXT(x)
    #else
        #error "define NTEXT macro"
    #endif
#else
    using std::string;
    #define String string
    #define NTEXT(x) (x)
#endif


EXPORT_DLL
enum enumCodePage
{
    keAnsi,
    keUTF8
};


const String SPACE = NTEXT(" ");
const String COMMA = NTEXT(",");
const String COLON = NTEXT(":");
const String SEMICOLON = NTEXT(";");
const String BACKSLASH = NTEXT("\\");
const String SLASH = NTEXT("/");
const String SLASHSLASH = NTEXT("//");
const String PERIOD = NTEXT(".");
const String DOTDOT = NTEXT("..");
const String EQUAL = NTEXT("=");
const String DASH = NTEXT("-");
const String AMPERSAND = NTEXT("&");
const String QUESTION = NTEXT("?");
const String EMPTYSTR = NTEXT("");
const String QUOTE = NTEXT("\"");
const String APOSTROPHE = NTEXT("'");
const String OPENANGLEBRACKET = NTEXT("<");
const String CLOSEANGLEBRACKET = NTEXT(">");
const String TAB = NTEXT("\t");
const String TRUE_STR = NTEXT("true");
const String FALSE_STR = NTEXT("false");
const String WS_PAT = NTEXT(" \t\r");

// String_H_LOADED
#endif