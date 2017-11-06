//
//  ViewController.m
//  NSExceptionDemo
//
//  Created by tenny on 06/11/2017.
//  Copyright © 2017 tenny. All rights reserved.
//

#import "ViewController.h"
#import "TestException.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    TestException *t = [[TestException alloc] init];
    
    for (int i = 0; i < 10; ++i) {
        [t add];
        [t print];
    }
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
