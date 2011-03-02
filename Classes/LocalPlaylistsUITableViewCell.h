//
//  PlaylistsUITableViewCell.h
//  iSub
//
//  Created by Ben Baron on 4/2/10.
//  Copyright 2010 Ben Baron. All rights reserved.
//

#import <UIKit/UIKit.h>

@class CellOverlay, iSubAppDelegate, ViewObjectsSingleton, MusicControlsSingleton, DatabaseControlsSingleton;

@interface LocalPlaylistsUITableViewCell : UITableViewCell 
{
	iSubAppDelegate *appDelegate;
	ViewObjectsSingleton *viewObjects;
	MusicControlsSingleton *musicControls;
	DatabaseControlsSingleton *databaseControls;
	
	NSIndexPath *indexPath;
	NSString *md5;
	
	UIImageView *deleteToggleImage;
	BOOL isDelete;
	
	UILabel *playlistCountLabel;
	UIScrollView *playlistNameScrollView;
	UILabel *playlistNameLabel;
	
	BOOL isOverlayShowing;
	CellOverlay *overlayView;
	
	CGPoint startTouchPosition;
	BOOL swiping;
	BOOL hasSwiped;
	BOOL fingerIsMovingLeftOrRight;
	BOOL fingerMovingVertically;
}

@property (nonatomic, retain) NSIndexPath *indexPath;
@property (nonatomic, retain) NSString *md5;

@property (nonatomic, retain) UIImageView *deleteToggleImage;
@property BOOL isDelete;

@property (nonatomic, retain) UILabel *playlistCountLabel;
@property (nonatomic, retain) UIScrollView *playlistNameScrollView;
@property (nonatomic, retain) UILabel *playlistNameLabel;

@property BOOL isOverlayShowing;
@property (nonatomic, retain) CellOverlay *overlayView;


- (BOOL)isTouchGoingLeftOrRight:(UITouch *)touch;
- (void)lookForSwipeGestureInTouches:(NSSet *)touches withEvent:(UIEvent *)event;
- (void)hideOverlay;
- (void)showOverlay;

- (void)toggleDelete;

@end