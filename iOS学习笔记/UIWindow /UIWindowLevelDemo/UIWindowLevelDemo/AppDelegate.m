//
//  AppDelegate.m
//  UIWindowLevelDemo
//
//  Created by tennyxu on 23/09/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "AppDelegate.h"
#import "ViewController.h"
#import "TTWindow.h"

@interface AppDelegate () {
  TTWindow *ttWindow;
}

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
  // Override point for customization after application launch.
  
  //http://www.cnblogs.com/smileEvday/archive/2012/03/27/2420362.html
  //坑，
  /*上午抽了点时间看了一下新创建window不显示的问题，我们在xcode5之后新创建的工程默认都是ARC的，这就导致在didFinishLaunch中创建的window没有人持有，从而在退出该函数时，这些window都会被释放掉，所以显示不出来。
   解决方案（二选一）：
   1、将工程改成非ARC
   2、要创建的window改称类的属性，避免出了函数时新创建的window被释放
   */
  /*
   在新版的Xcode6中，如果如果是同级的level的window，他们的显示顺序是按照 [_window makeKeyAndVisible];
   的顺序显示的。
   */
  /*
   UIWindow在执行[self.window makeKeyAndVisible]时，一定要持有一个ViewController
   这样才能用ViewController的view作为去填充window的内容
   */
  
  self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
  self.window.backgroundColor = [UIColor yellowColor];
  
  
  ViewController *vc = [[ViewController alloc] init];
  self.window.rootViewController = vc;
  [self.window makeKeyAndVisible];
  
  //ttWindow
  ttWindow = [[TTWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
  ttWindow.rootViewController = vc;
  [ttWindow makeKeyAndVisible];
  
  
  self.normalWindow = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
  self.normalWindow.backgroundColor = [UIColor blueColor];
  self.normalWindow.windowLevel = UIWindowLevelNormal;
  self.normalWindow.rootViewController = vc;
  [self.normalWindow makeKeyAndVisible];
  
  CGRect windowRect = CGRectMake(50, 50, self.window.screen.bounds.size.width-100, self.window.screen.bounds.size.height -100);
  
  self.alertLevelWindow = [[UIWindow alloc] initWithFrame:windowRect];
  self.alertLevelWindow.backgroundColor = [UIColor redColor];
  self.alertLevelWindow.windowLevel = UIWindowLevelAlert;
  self.alertLevelWindow.rootViewController = vc;
  [self.alertLevelWindow makeKeyAndVisible];
  
  self.statusLevelWindow = [[UIWindow alloc] initWithFrame:CGRectMake(0, 50, 320, 20)];
  self.statusLevelWindow.windowLevel = UIWindowLevelStatusBar;
  self.statusLevelWindow.backgroundColor = [UIColor blackColor];
  self.statusLevelWindow.rootViewController = vc;
  [self.statusLevelWindow makeKeyAndVisible];
  
  NSLog(@"Normal window level: %f", UIWindowLevelNormal);
  NSLog(@"Alert window level: %f", UIWindowLevelAlert);
  NSLog(@"Status window level: %f", UIWindowLevelStatusBar);
  
  if ([self.statusLevelWindow isKeyWindow]) {
    NSLog(@"statusLevelWindow isKeyWindow ");
  } else {
    NSLog(@"statusLevelWindow is not KeyWindow ");
  }
  
  if ([self.alertLevelWindow isKeyWindow]) {
    NSLog(@"alertLevelWindow isKeyWindow ");
  } else {
    NSLog(@"alertLevelWindow is not KeyWindow ");
  }
  
  if ([self.normalWindow isKeyWindow]) {
    NSLog(@"normalWindow isKeyWindow ");
  } else {
    NSLog(@"normalWindow is not KeyWindow ");
  }
  
  if ([self.window isKeyWindow]) {
    NSLog(@"window isKeyWindow ");
  } else {
    NSLog(@"window is not KeyWindow ");
  }
  
  if ([ttWindow isKeyWindow]) {
    NSLog(@"ttWindow isKeyWindow ");
  } else {
    NSLog(@"ttWindow is not KeyWindow ");
  }
  
//  /*
//   * 1 监测window通知
//   */
//  [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(windowsDidBecomeVisible:) name:UIWindowDidBecomeVisibleNotification object:self.window];
//
//  [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(windowDidBecomeHidden:) name:UIWindowDidBecomeHiddenNotification object:self.window];
//
//  [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(windowsDidBecomeKey:) name:UIWindowDidBecomeKeyNotification object:self.window];
//
//  [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(windowDidResignKey:) name:UIWindowDidResignKeyNotification object:self.window];
  
  
  
  return YES;
}
//////貌似，UIWindow实现了这个方法，也没有用，所以还是得子类实现
//- (void)becomeKeyWindow {
//  NSLog(@"becomeKeyWindow");
//}
//- (void)resignKeyWindow {
//  NSLog(@"resignKeyWindow");
//}
//

//- (void)windowsDidBecomeVisible:(UIWindow *)window {
//  NSLog(@"%@,%@",NSStringFromSelector(_cmd),window);
//}
//
//- (void)windowDidBecomeHidden:(UIWindow *)window {
//   NSLog(@"%@,%@",NSStringFromSelector(_cmd),window);
//}
//
//- (void)windowsDidBecomeKey:(UIWindow *)window {
//   NSLog(@"%@,%@",NSStringFromSelector(_cmd),window);
//}
//
//- (void)windowDidResignKey:(UIWindow *)window {
//   NSLog(@"%@,%@",NSStringFromSelector(_cmd),window);
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
