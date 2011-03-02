//
//  PlaylistSongsViewController.h
//  iSub
//
//  Created by Ben Baron on 4/2/10.
//  Copyright 2010 Ben Baron. All rights reserved.
//

#import <UIKit/UIKit.h>

@class iSubAppDelegate, ViewObjectsSingleton, MusicControlsSingleton, DatabaseControlsSingleton, EGORefreshTableHeaderView;

@interface PlaylistSongsViewController : UITableViewController
{
	iSubAppDelegate *appDelegate;	
	ViewObjectsSingleton *viewObjects;
	MusicControlsSingleton *musicControls;
	DatabaseControlsSingleton *databaseControls;

	NSString *md5;
	
	NSMutableData *receivedData;
	NSURLConnection *connection;
	
	NSUInteger playlistCount;
	
	EGORefreshTableHeaderView *refreshHeaderView;
	BOOL _reloading;
}

@property(assign,getter=isReloading) BOOL reloading;

@property (nonatomic, retain) NSString *md5;

@end