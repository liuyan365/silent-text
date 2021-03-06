/*
Copyright © 2012-2013, Silent Circle, LLC.  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Any redistribution, use, or modification is done solely for personal 
      benefit and not for any commercial purpose or for monetary gain
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name Silent Circle nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL SILENT CIRCLE, LLC BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
//
//  XMPPServer.h
//  SilentChat
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

#import "XMPPFramework.h"

extern NSUInteger kXMPPDefaultPort;

@class SCAccount;

@interface XMPPServer : NSObject <XMPPStreamDelegate, XMPPReconnectDelegate>

@property (strong, nonatomic) SCAccount *account;
@property (copy,   nonatomic) XMPPJID *myJID; // This is assigned to the xmppStream's myJID.
@property (nonatomic) BOOL allowSelfSignedCertificates; // Default: NO;
@property (nonatomic) BOOL allowSSLHostNameMismatch;    // Default: NO;
@property (strong, nonatomic, readonly) XMPPStream *xmppStream;
@property (strong, nonatomic, readonly) XMPPReconnect *xmppReconnect;
@property (strong, nonatomic, readonly) XMPPCapabilities *xmppCapabilities;
@property (strong, nonatomic, readonly) XMPPCapabilitiesCoreDataStorage *xmppCapabilitiesStorage;
@property (strong, nonatomic, readonly) NSManagedObjectContext *mocCapabilities;

- (XMPPServer *)         initWithAccount: (SCAccount *) account;
- (XMPPStream *) updateStreamWithAccount: (SCAccount *) account; // Update to change the account information.

- (XMPPStream *) activate;

- (BOOL)            connect;
- (XMPPServer *) disconnect;
- (XMPPServer *) disconnectAfterSending;

- (XMPPStream *) changeAccount: (SCAccount *) account;

@end
