//
//  SBWorkaround.h
//  The Hit List Start Menu
//
//  Created by Du Song on 2015-01-28.
//  Copyright (c) 2015 Song Du. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SBWorkaround : NSObject
+ (NSString *)getTitle:(id) object; // TODO: Workaround, otherwise compile fail when call task.title
@end
