//
//  ViewController.m
//  CJHDemo
//
//  Created by tennyxu on 23/08/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
  [super viewDidLoad];
  // Do any additional setup after loading the view, typically from a nib.
  NSString *path = NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES).firstObject;
  NSLog(@"%@",path);
  
  NSString *filename = [path stringByAppendingPathComponent:@"123.plist"];
  
//  NSNumber *num = [[NSNumber alloc] initWithInt:0];
  
  
  NSArray *array = @[@"123", @"456", @"789"];
  [array writeToFile:filename atomically:YES];
  
  NSArray *result = [NSArray arrayWithContentsOfFile:filename];
  NSLog(@"%@", result);
  
}


- (void)didReceiveMemoryWarning {
  [super didReceiveMemoryWarning];
  // Dispose of any resources that can be recreated.
}


@end
