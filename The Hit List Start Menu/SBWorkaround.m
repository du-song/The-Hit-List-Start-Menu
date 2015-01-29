//
//  SBWorkaround.m
//  The Hit List Start Menu
//
//  Created by Du Song on 2015-01-28.
//  Copyright (c) 2015 Song Du. All rights reserved.
//

#import "SBWorkaround.h"
#import <objc/runtime.h>

@implementation SBWorkaround
+ (NSString *)getTitle:(id) object {
	return [object title];
}
+ (NSString *)getUrl:(id) object {
	return object ? objc_msgSend(object, @selector(url)) : @"";
}
@end
