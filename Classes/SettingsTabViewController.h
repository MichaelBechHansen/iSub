//
//  SettingsTabViewController.h
//  iSub
//
//  Created by Ben Baron on 6/29/10.
//  Copyright 2010 Ben Baron. All rights reserved.
//

#import <UIKit/UIKit.h>

@class iSubAppDelegate, ViewObjectsSingleton, MusicControlsSingleton, SocialControlsSingleton, DatabaseControlsSingleton;

@interface SettingsTabViewController : UIViewController 
{
	iSubAppDelegate *appDelegate;
	ViewObjectsSingleton *viewObjects;
	MusicControlsSingleton *musicControls;
	SocialControlsSingleton *socialControls;
	DatabaseControlsSingleton *databaseControls;
	
	UIViewController *parentController;
	
	IBOutlet UILabel *versionLabel;
	
	IBOutlet UISwitch *manualOfflineModeSwitch;
	
	IBOutlet UISwitch *checkUpdatesSwitch;
	
	IBOutlet UISwitch *autoReloadArtistSwitch;
	
	IBOutlet UISwitch *disablePopupsSwitch;
	
	IBOutlet UISwitch *disableRotationSwitch;
	
	IBOutlet UISwitch *enableSongsTabSwitch;
	IBOutlet UILabel *enableSongsTabLabel;
	IBOutlet UILabel *enableSongsTabDesc;
	
	IBOutlet UISegmentedControl *recoverSegmentedControl;
	IBOutlet UISegmentedControl *maxBitrateWifiSegmentedControl;
	IBOutlet UISegmentedControl *maxBitrate3GSegmentedControl;
	
	IBOutlet UISwitch *enableLyricsSwitch;
	IBOutlet UISwitch *autoPlayerInfoSwitch;
	
	IBOutlet UISwitch *enableSongCachingSwitch;
	
	IBOutlet UILabel *enableNextSongCacheLabel;
	IBOutlet UISwitch *enableNextSongCacheSwitch;
	
	IBOutlet UISegmentedControl *cachingTypeSegmentedControl;
	
	unsigned long long int totalSpace;
	unsigned long long int freeSpace;
	IBOutlet UILabel *cacheSpaceLabel1;
	IBOutlet UILabel *cacheSpaceLabel2;
	IBOutlet UILabel *freeSpaceLabel;
	IBOutlet UILabel *totalSpaceLabel;
	IBOutlet UIView *totalSpaceBackground;
	IBOutlet UIView *freeSpaceBackground;
	IBOutlet UISlider *cacheSpaceSlider;
	IBOutlet UILabel *cacheSpaceDescLabel;
	
	IBOutlet UISwitch *autoDeleteCacheSwitch;
	IBOutlet UISegmentedControl *autoDeleteCacheTypeSegmentedControl;
	IBOutlet UISegmentedControl *cacheSongCellColorSegmentedControl;
	
	IBOutlet UIButton *twitterSigninButton;
	IBOutlet UILabel *twitterStatusLabel;
	IBOutlet UISwitch *twitterEnabledSwitch;
	
	IBOutlet UISwitch *enableScrobblingSwitch;
	IBOutlet UILabel *scrobblePercentLabel;
	IBOutlet UISlider *scrobblePercentSlider;
	
	NSDate *loadedTime;
}

@property (nonatomic, retain) UIViewController *parentController;

@property (nonatomic, retain) NSDate *loadedTime;

- (void) toggleCacheControlsVisibility;
- (void) cachingTypeToggle;
- (IBAction) segmentAction:(id)sender;
- (IBAction) switchAction:(id)sender;
- (IBAction) updateMinFreeSpaceLabel;
- (IBAction) updateMinFreeSpaceSetting;
- (IBAction) revertMinFreeSpaceSlider;
- (IBAction) twitterButtonAction;
- (IBAction) updateScrobblePercentLabel;
- (IBAction) updateScrobblePercentSetting;

@end