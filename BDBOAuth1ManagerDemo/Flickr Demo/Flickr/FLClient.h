//
//  FLClient.h
//
//  Copyright (c) 2014 Bradley David Bergeron
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy of
//  this software and associated documentation files (the "Software"), to deal in
//  the Software without restriction, including without limitation the rights to
//  use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
//  the Software, and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
//  FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
//  COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
//  IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
//  CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

@import Foundation;

#import "BDBOAuth1RequestOperationManager.h"
#import "BDBOAuth1SessionManager.h"
#import "FLPhotoset.h"
#import "FLPhoto.h"


FOUNDATION_EXPORT NSString * const FLClientErrorDomain;

FOUNDATION_EXPORT NSString * const FLClientDidLogInNotification;
FOUNDATION_EXPORT NSString * const FLClientDidLogOutNotification;


#pragma mark -
@interface FLClient : NSObject

@property (nonatomic, assign, readonly, getter = isAuthorized) BOOL authorized;

#pragma mark Initialization
+ (instancetype)createWithAPIKey:(NSString *)apiKey secret:(NSString *)secret;
+ (instancetype)sharedClient;

#pragma mark Authorization
- (BOOL)isAuthorized;
+ (BOOL)isAuthorizationCallbackURL:(NSURL *)url;
- (void)authorize;
- (BOOL)handleAuthorizationCallbackURL:(NSURL *)url;
- (void)deauthorize;

#pragma mark Photosets
- (void)getPhotosetsWithCompletion:(void (^)(NSSet *photosets, NSError *error))completion;

#pragma mark Photos
- (void)getPhotosInPhotoset:(FLPhotoset *)photoset completion:(void (^)(NSArray *photos, NSError *error))completion;

@end
