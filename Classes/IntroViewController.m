//
//  IntroViewController.m
//  iSub
//
//  Created by Ben Baron on 1/27/11.
//  Copyright 2011 Ben Baron. All rights reserved.
//

#import "IntroViewController.h"
#import "iSubAppDelegate.h"
#import "ServerListViewController.h"
#import <MediaPlayer/MediaPlayer.h>

@implementation IntroViewController

-(BOOL) shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)inOrientation 
{
	if ([[[iSubAppDelegate sharedInstance].settingsDictionary objectForKey:@"lockRotationSetting"] isEqualToString:@"YES"])
		return NO;
	
    return YES;
}

- (void)didReceiveMemoryWarning 
{
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc. that aren't in use.
}

- (void)viewDidLoad
{
	[super viewDidLoad];
	
	if (IS_IPAD())
		sunkenLogo.autoresizingMask = UIViewAutoresizingFlexibleLeftMargin | UIViewAutoresizingFlexibleTopMargin | UIViewAutoresizingFlexibleRightMargin | UIViewAutoresizingFlexibleBottomMargin;
}

- (void)viewDidUnload 
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (IBAction)buttonPress:(id)sender
{
	iSubAppDelegate *appDelegate = [iSubAppDelegate sharedInstance];

	if (sender == introVideo)
	{
		NSURL *introUrl = nil;
		if (IS_IPAD())
			introUrl = [NSURL URLWithString:@"http://isubapp.com/intro/ipad/prog_index.m3u8"];
		else if (appDelegate.isHighRez)
			introUrl = [NSURL URLWithString:@"http://isubapp.com/intro/iphone4/prog_index.m3u8"];
		else
			introUrl = [NSURL URLWithString:@"http://isubapp.com/intro/iphone/prog_index.m3u8"];
		
		if ([MPMoviePlayerController instancesRespondToSelector:@selector(view)]) 
		{
			// Running on 3.2+
			MPMoviePlayerViewController *moviePlayer = [[MPMoviePlayerViewController alloc] initWithContentURL:introUrl];
			// Assuming self is a UIViewController
			[self presentMoviePlayerViewControllerAnimated:moviePlayer];
			// This line might be needed
			[moviePlayer.moviePlayer play];
		} 
		else 
		{
			MPMoviePlayerController *moviePlayer= [[MPMoviePlayerController alloc] initWithContentURL:introUrl];
			[moviePlayer play];
		}	
	}
	else if (sender == testServer)
	{
		[self dismissModalViewControllerAnimated:YES];
	}
	else if (sender == ownServer)
	{
		ServerListViewController *serverListViewController = [[ServerListViewController alloc] initWithNibName:@"ServerListViewController" bundle:nil];
		serverListViewController.hidesBottomBarWhenPushed = YES;
		
		[self dismissModalViewControllerAnimated:NO];

		if (IS_IPAD())
		{
			[appDelegate.homeNavigationController pushViewController:serverListViewController animated:YES];
		}
		else
		{
			appDelegate.currentTabBarController.selectedIndex = 0;
			[(UINavigationController*)appDelegate.currentTabBarController.selectedViewController pushViewController:serverListViewController animated:YES];
		}
		
		[serverListViewController release];
	}
}


- (void)dealloc 
{
    [super dealloc];
}


@end