//
//  FirstViewController.m
//  CustomViewDemo
//
//  Created by 徐涛 on 07/08/2017.
//  Copyright © 2017 徐涛. All rights reserved.
//

#import "FirstViewController.h"
#import "CustomDogView.h"
#import "CustomDogViewModel.h"

@interface FirstViewController ()

@end

@implementation FirstViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    CustomDogView *customDogView = [[CustomDogView alloc] initWithFrame:CGRectMake(20.0, 20.0, 40.0, 100.0)];
    CustomDogViewModel *customDogViewModel = [CustomDogViewModel modelWithName:@"Test" andPic:@"first"];
    customDogView.model = customDogViewModel;
    [self.view addSubview:customDogView];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
