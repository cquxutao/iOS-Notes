//
//  FirstViewController.m
//  iPhoneXTabbarDemo
//
//  Created by tennyxu on 13/09/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "FirstViewController.h"
#import "TTScrollView.h"
#import "TTCommonMacros.h"

@interface FirstViewController () <UIScrollViewDelegate>

@property (nonatomic,strong) TTScrollView *ttScrollView;
@property (nonatomic,strong) UILabel *disDragonState;

@end

@implementation FirstViewController

- (void)viewDidLoad {
  [super viewDidLoad];
  // Do any additional setup after loading the view, typically from a nib.
  
  self.navigationController.navigationBar.backgroundColor = [UIColor redColor];
  [self addTTScrollView];
  [self addDisDragonState];
}

- (void)viewDidLayoutSubviews {
  _ttScrollView.contentSize = CGSizeMake(SCREEN_WIDTH * 2, 200);
  UILabel *dragonLabel = [[UILabel alloc] init];
  dragonLabel.frame = CGRectMake(100.0, 100.0, 50.0, 50.0);
  dragonLabel.backgroundColor = [UIColor blackColor];
  [_ttScrollView addSubview:dragonLabel];
}

- (void)viewDidAppear:(BOOL)animated {
  [super viewWillAppear:animated];

}

- (void)didReceiveMemoryWarning {
  [super didReceiveMemoryWarning];
  // Dispose of any resources that can be recreated.
}

#pragma mark Private Method

- (void)addTTScrollView {
  _ttScrollView = [[TTScrollView alloc] initWithFrame:CGRectMake(0, 100, SCREEN_WIDTH, 200)];
  _ttScrollView.backgroundColor = [UIColor colorWithRed:240.0 / 255.0 green:200.0 /255.0 blue:200.0/255.0 alpha:1.0];
  _ttScrollView.delegate = self;
  [self.view addSubview:_ttScrollView];
}

- (void)addDisDragonState {
  _disDragonState = [[UILabel alloc] init];
  _disDragonState.backgroundColor = [UIColor blackColor];
  _disDragonState.frame = CGRectMake(40, 400, 50.0, 50.0);
  [self.view addSubview:_disDragonState];
}

#pragma mark UIScrollViewDelegate

- (void)scrollViewDidScroll:(UIScrollView *)scrollView {
  if (scrollView.contentOffset.x > 150) {
    _disDragonState.hidden = YES;
  } else {
    _disDragonState.hidden = NO;
  }
  
}
@end
