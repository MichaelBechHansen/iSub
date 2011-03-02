//
//  NewHomeViewController.h
//  iSub
//
//  Created by bbaron on 11/6/10.
//  Copyright 2010 Ben Baron. All rights reserved.
//

#import <UIKit/UIKit.h>

@class iSubAppDelegate, ViewObjectsSingleton, MusicControlsSingleton, DatabaseControlsSingleton;

@interface NewHomeViewController : UIViewController 
{
	iSubAppDelegate *appDelegate;
	ViewObjectsSingleton *viewObjects;
	MusicControlsSingleton *musicControls;
	DatabaseControlsSingleton *databaseControls;
	
	IBOutlet UIButton *playerButton;
	IBOutlet UIButton *jukeboxButton;
	IBOutlet UISearchBar *searchBar;
	IBOutlet UISegmentedControl *searchSegment;
	IBOutlet UIView *searchSegmentBackground;
	UIView *searchOverlay;
	UIButton *dismissButton;
	
	BOOL isSearch;
	NSMutableData *receivedData;
}

- (IBAction)quickAlbums;
- (IBAction)serverShuffle;
- (IBAction)settings;
- (IBAction)player;
- (IBAction)jukebox;
- (IBAction)chat;

@end