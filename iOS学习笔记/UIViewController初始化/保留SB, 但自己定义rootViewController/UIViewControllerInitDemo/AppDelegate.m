//
//  AppDelegate.m
//  UIViewControllerInitDemo
//
//  Created by tennyxu on 23/09/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "AppDelegate.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
  // Override point for customization after application launch.
  
  self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
  
  
  UIStoryboard *storyboard = [UIStoryboard storyboardWithName:@"Main" bundle:nil];

  //加载箭头指向的控制器
//  UIViewController *vc = [storyboard instantiateInitialViewController];
  //
  
  //加载有标示的控制器
  //踩过的坑
  //在info.plist 里面,有个Main storyboard file base name 属性,默认为Main;但因为现在没有了"is inital View Controller"那个指向的箭头了，所以要去掉那个Main属性，活着设置为空，这样就不会存在“[Application] Failed to instantiate the default view controller for UIMainStoryboardFile 'Main' - perhaps the designated entry point is not set?”这个警告了
  //https://stackoverflow.com/questions/20875823/ios-7-failing-to-instantiate-default-view-controller
  //If you do it programmatically, be sure to remove your storyboard from your target's Main Interface - just leave it blank. Also this should go in didFinishLaunchingWithOptions
  
  UIViewController *vc = [storyboard instantiateViewControllerWithIdentifier:@"ViewControllerID"];

  self.window.rootViewController = vc;

  [self.window makeKeyAndVisible];
  
  return YES;
}


- (void)applicationWillResignActive:(UIApplication *)application {
  // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
  // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
  // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
  // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
  // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
  // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}


- (void)applicationWillTerminate:(UIApplication *)application {
  // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}


@end
