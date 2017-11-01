//
//  AppDelegate.m
//  UIWindowNotification
//
//  Created by tennyxu on 23/09/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "AppDelegate.h"
#import "ViewController.h"

@interface AppDelegate () <UITextFieldDelegate>

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
  // Override point for customization after application launch.
  
  ViewController *vc = [[ViewController alloc] init];
  NSSet *set = [NSSet setWithObjects:vc, nil];
  

  
  /*
   * 1 监测window
   */
  //为什么，监测的代码，要放在前面，才有效
  //并且，监测通知的函数，先执行
//  [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(windowDidBecomeVisible:) name:UIWindowDidBecomeVisibleNotification object:nil];
//
//  [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(windowDidBecomeHidden:) name:UIWindowDidBecomeHiddenNotification object:nil];
//
//  [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(windowDidBecomeKey:) name:UIWindowDidBecomeKeyNotification object:nil];
//
//  [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(windowDidResignKey:) name:UIWindowDidResignKeyNotification object:nil];
  
//  [self addWindow000:set];
//  [self addWindow1:set];
//  [self addWindow2:set];
  
  
  NSArray *arr = [set allObjects];
  
  self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
  
  
  self.window.backgroundColor = [UIColor purpleColor];
  self.window.windowLevel = UIWindowLevelNormal;
  
  UITextField *tf0 = [[UITextField alloc] initWithFrame:CGRectMake(0, 20, 100, 20)];
  tf0.layer.borderColor = [UIColor blueColor].CGColor;
  tf0.layer.borderWidth = 1;
  tf0.delegate = self;
  
  UILabel *label0 = [[UILabel alloc] initWithFrame:CGRectMake(0, 40, 100, 20)];
  label0.text = @"0";
  label0.font = [UIFont boldSystemFontOfSize:18];
  
  self.window.rootViewController = arr[0];
  
  [self.window.rootViewController.view addSubview:tf0];
  [self.window.rootViewController.view addSubview:label0];
  
  
  [self.window makeKeyAndVisible];
  
  
  
  
  
  
  
  return YES;
}

#pragma mark Window0

- (void)addWindow000:(NSSet *)objects {
  NSArray *arr = [objects allObjects];
  
  NSLog(@"%@,%@",NSStringFromSelector(_cmd),objects);
  self.window0 = [[TTWindow alloc] initWithFrame:CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height)];
  
  
  self.window0.backgroundColor = [UIColor purpleColor];
  self.window0.windowLevel = UIWindowLevelNormal;
  self.window0.windowName = @"window0";
  
  UITextField *tf0 = [[UITextField alloc] initWithFrame:CGRectMake(0, 20, 100, 20)];
  tf0.layer.borderColor = [UIColor blueColor].CGColor;
  tf0.layer.borderWidth = 1;
  tf0.delegate = self;
  
  UILabel *label0 = [[UILabel alloc] initWithFrame:CGRectMake(0, 40, 100, 20)];
  label0.text = @"1";
  label0.font = [UIFont boldSystemFontOfSize:18];
  
  [self.window0 addSubview:tf0];
  [self.window0 addSubview:label0];
  
  self.window0.rootViewController = arr[0];
  [self.window0 makeKeyAndVisible];
}

#pragma mark Window1
//
//- (void)addWindow1:(NSSet *)objects {
//  NSArray *arr = [objects allObjects];
//
//  NSLog(@"%@,%@",NSStringFromSelector(_cmd),objects);
//  self.window1 = [[TTWindow alloc] initWithFrame:CGRectMake(100, 100, [UIScreen mainScreen].bounds.size.width-100, [UIScreen mainScreen].bounds.size.height-100)];
//  self.window1.backgroundColor = [UIColor brownColor];
//  self.window1.windowLevel = UIWindowLevelStatusBar;
//  self.window1.windowName = @"window1";
//
//  UITextField *tf0 = [[UITextField alloc] initWithFrame:CGRectMake(0, 0, 100, 20)];
//  tf0.layer.borderColor = [UIColor blueColor].CGColor;
//  tf0.layer.borderWidth = 1;
//  tf0.delegate = self;
//
//  UILabel *label0 = [[UILabel alloc] initWithFrame:CGRectMake(0, 40, 100, 20)];
//  label0.text = @"2";
//  label0.font = [UIFont boldSystemFontOfSize:18];
//
//  [self.window1 addSubview:tf0];
//  [self.window1 addSubview:label0];
//
//  self.window1.rootViewController = arr[0];
//  [self.window1 makeKeyAndVisible];
//}
//
//#pragma mark Window2
//
//- (void)addWindow2:(NSSet *)objects {
//  NSArray *arr = [objects allObjects];
//
//  NSLog(@"%@,%@",NSStringFromSelector(_cmd),objects);
//  self.window2 = [[TTWindow alloc] initWithFrame:CGRectMake(200, 200, [UIScreen mainScreen].bounds.size.width-200, [UIScreen mainScreen].bounds.size.height-200)];
//  self.window2.backgroundColor = [UIColor redColor];
//  self.window2.windowLevel = UIWindowLevelAlert;
//  self.window2.windowName = @"window2";
//
//  UITextField *tf0 = [[UITextField alloc] initWithFrame:CGRectMake(0, 0, 100, 20)];
//  tf0.layer.borderColor = [UIColor blueColor].CGColor;
//  tf0.layer.borderWidth = 1;
//  tf0.delegate = self;
//
//  UILabel *label0 = [[UILabel alloc] initWithFrame:CGRectMake(0, 40, 100, 20)];
//  label0.text = @"2";
//  label0.font = [UIFont boldSystemFontOfSize:18];
//
//  [self.window2 addSubview:tf0];
//  [self.window2 addSubview:label0];
//
//  self.window2.rootViewController = arr[0];
//  [self.window2 makeKeyAndVisible];
//}

//#pragma mark Window Notification
//- (void)windowDidBecomeVisible:(NSNotification *)notification {
//  NSLog(@"1  1-------  windowDidBecomeVisible");
//}
//
//- (void)windowDidBecomeHidden:(NSNotification *)notification {
//  NSLog(@"1  --2-----  windowDidBecomeHidden");
//}
//
//- (void)windowDidBecomeKey:(NSNotification *)notification {
//  NSLog(@"1  ----3---  windowDidBecomeKey");
//}
//
//- (void)windowDidResignKey:(NSNotification *)notification {
//  NSLog(@"1  ------4-  windowDidResignKey");
//}


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
