
#if !defined(HttpClientPost_H_LOADED)
#define HttpClientPost_H_LOADED

// [
// $        HttpClientPost.h
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
// Copyright (c) 1998-2002 Chris Sanchez. All rights reserved.
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
//                 $Revision:$
//                 $Author:$
//                 $Date:$
// 
// ]

#include <cslib.h>
#include <net/NetSocket.h>
#include <thd/ThdCriticalSection.h>
#include <util/UtilMapping.h>
#include <util/UtilRefCountedPtr.h>


class HttpContent;

class HttpClientPost
{
public:
    HttpClientPost();
    virtual ~HttpClientPost();

    //
    // Set server info ...
    //
    void setServerURL(const String& serverURL);
    void setProxyServer(const String& server, const unsigned short port);

    
    //
    // Send the request ...
    //
    virtual bool send(const HttpContent& httpRequest,
                      HttpContent&       httpReply);
    //
    // Abort the request ...
    //     Allows the send() to be aborted from a different thread.
    //
    virtual void abortSend();
 
    
protected:
    mutable ThdCriticalSection m_sendMutex;

    RefCountedPtr<Socket> m_socket;
    bool m_abort;

    String m_serverURL;
    String m_server;
    unsigned short m_serverPort;
    String m_serverPath;

    String m_proxyServer;
    unsigned short m_proxyPort;

    
   
    bool doSend(const String& server,
                const unsigned short   port,
                const HttpContent& httpRequest,
                      HttpContent& httpReply);
 
 
private:
    //
    // Disable copy constructor and assignment operator
    //
    HttpClientPost(const HttpClientPost&);
    HttpClientPost& operator=(const HttpClientPost&);
};



#endif   // HttpClientPost_H_LOADED
