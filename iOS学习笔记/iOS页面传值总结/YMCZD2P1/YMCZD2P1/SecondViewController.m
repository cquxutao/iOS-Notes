//
//  SecondViewController.m
//  YMCZD2P1
//
//  Created by tennyxu on 19/08/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "SecondViewController.h"

static int number;

@interface SecondViewController () {
    struct {
        unsigned int increment:1;
    } _delegateFlag;
}

- (IBAction)add1:(id)sender;

@end

@implementation SecondViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
//    //这样写，不会调用getter/setter方法,基本功都不会
//    _delegate = [self.tabBarController.viewControllers objectAtIndex:0];
    
    self.delegate = [self.tabBarController.viewControllers objectAtIndex:0];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
#pragma mark -- setter/getter
- (void)setDelegate:(id<SecondViewControllerDelegate>)delegate {
    _delegate = delegate;
    _delegateFlag.increment = [_delegate respondsToSelector:@selector(increment: withdata:)];
}

- (IBAction)add1:(id)sender {
    ++number;
    if (_delegateFlag.increment) {
        [_delegate increment:self withdata:number];
    }
}
@end
