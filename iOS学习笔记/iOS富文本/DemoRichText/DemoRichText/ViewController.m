//
//  ViewController.m
//  DemoRichText
//
//  Created by tennyxu on 19/09/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
  [super viewDidLoad];
  // Do any additional setup after loading the view, typically from a nib.
  //富文本
  UILabel *dis = [[UILabel alloc] initWithFrame:CGRectMake(200, 200, 300, 20)];

  NSString *str = @"12:00";
  NSInteger apple = 1;
  NSInteger orange = 2;
  NSInteger all = apple + orange;
  NSLog(@"%ld",(long)all);

  NSMutableAttributedString *mutableAttributedString = [[NSMutableAttributedString alloc] initWithString:str];
//  [mutableAttributedString addAttribute:NSForegroundColorAttributeName value:[UIFont systemFontOfSize:13]range:NSMakeRange(0, 5)];

  NSTextAttachment *textAttachmentImage = [[NSTextAttachment alloc] init];
  UIImage *timeImage = [UIImage imageNamed:@"time"];
  textAttachmentImage.image = timeImage;
  textAttachmentImage.bounds = CGRectMake(0.0, 0.0, 20, 20);


  NSAttributedString *attributedString = [NSAttributedString attributedStringWithAttachment:textAttachmentImage];


  [mutableAttributedString insertAttributedString:attributedString atIndex:0];

  dis.attributedText = mutableAttributedString;

  [self.view addSubview:dis];

  [self test2];
  
}

- (void)test2 {
  NSMutableArray *arr1 = [@[@1] mutableCopy];
  NSMutableArray *arr2 = [@[@2] mutableCopy];
  [arr1 addObject:arr2];
  [arr2 addObject:arr1];
}

- (void)didReceiveMemoryWarning {
  [super didReceiveMemoryWarning];
  // Dispose of any resources that can be recreated.
}


@end
