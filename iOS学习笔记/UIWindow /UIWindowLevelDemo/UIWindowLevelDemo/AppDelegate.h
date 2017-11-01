//
//  AppDelegate.h
//  UIWindowLevelDemo
//
//  Created by tennyxu on 23/09/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>
//@interface AppDelegate: UIWindow <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;
@property (strong, nonatomic) UIWindow *normalWindow;
@property (strong, nonatomic) UIWindow *alertLevelWindow;
@property (strong, nonatomic) UIWindow *statusLevelWindow;

@end

