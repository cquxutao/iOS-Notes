//
//  ViewController.m
//  DemoInit
//
//  Created by tennyxu on 26/09/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "ViewController.h"
#import "TTView.h"

@interface ViewController ()

@property (nonatomic,strong) TTView *ttView;
@property (strong, nonatomic) IBOutlet TTView *tt;


@end

@implementation ViewController

- (void)viewDidLoad {
  [super viewDidLoad];
  // Do any additional setup after loading the view, typically from a nib.
//  self.tt =
  _ttView = [[TTView alloc] init];
  _ttView.frame = CGRectMake(10, 20, 100, 100);
  _ttView.backgroundColor = [UIColor purpleColor];
  [self.view addSubview:_ttView];
}


- (void)didReceiveMemoryWarning {
  [super didReceiveMemoryWarning];
  // Dispose of any resources that can be recreated.
}


@end
