//
//  ViewController.m
//  DemoImgeScale
//
//  Created by tennyxu on 20/09/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
  [super viewDidLoad];
  // Do any additional setup after loading the view, typically from a nib.
  UIImage *image = [UIImage imageNamed:@"jiaobao"];
  UIImageView *imageView = [[UIImageView alloc] initWithFrame:CGRectMake(100, 100, 40, 40)];
  imageView.backgroundColor = [UIColor grayColor];
  imageView.image = image;
  [imageView setContentMode:UIViewContentModeCenter];
  [self.view addSubview:imageView];
  
  UIImage *image2 =[image stretchableImageWithLeftCapWidth:image.size.width*0.5 topCapHeight:0];
  
  UIImageView *imageView2 = [[UIImageView alloc] initWithFrame:CGRectMake(100, 300, 80, 40)];
  imageView2.backgroundColor = [UIColor grayColor];
  imageView2.image = image2;
//  [imageView2 setContentMode:UIViewContentModeCenter];
  [self.view addSubview:imageView2];
  
}


- (void)didReceiveMemoryWarning {
  [super didReceiveMemoryWarning];
  // Dispose of any resources that can be recreated.
}


@end
