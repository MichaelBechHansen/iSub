//
//  NSString+hex.h
//  iSub
//
//  Created by Ben Baron on 10/20/10.
//  Copyright 2010 Ben Baron. All rights reserved.
//


@interface NSString (hex) 

	+ (NSString *) stringFromHex:(NSString *)str;
	+ (NSString *) stringToHex:(NSString *)str;

@end