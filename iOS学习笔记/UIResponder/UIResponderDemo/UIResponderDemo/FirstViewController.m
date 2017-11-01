//
//  FirstViewController.m
//  UIResponderDemo
//
//  Created by tennyxu on 26/09/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "FirstViewController.h"

@interface FirstViewController () <UITextFieldDelegate>
@property (strong, nonatomic) IBOutlet UITextField *tf;
@property (strong, nonatomic) IBOutlet UILabel *label;

@end

@implementation FirstViewController

- (void)viewDidLoad {
  [super viewDidLoad];
  // Do any additional setup after loading the view, typically from a nib.
//  NSLog(@"%@",NSStringFromSelector(_cmd));
//  NSLog(@"%d",self.isFirstResponder);
  _tf.delegate = self;
}


- (void)didReceiveMemoryWarning {
  [super didReceiveMemoryWarning];
  // Dispose of any resources that can be recreated.
}

#pragma mark UIResponder

//- (BOOL)isFirstResponder {
//  NSLog(@"%@",NSStringFromSelector(_cmd));
//  return true;
//}

#pragma mark UITextFieldDelegate

- (BOOL)textFieldShouldBeginEditing:(UITextField *)textField {
  return YES;
}

- (void)textFieldDidBeginEditing:(UITextField *)textField {
  
//  if ([_tf isEqual:textField]) {
//    self.label.text = textField.text;
//  }
  
}

- (BOOL)textFieldShouldEndEditing:(UITextField *)textField {
  return YES;
}

- (void)textFieldDidEndEditing:(UITextField *)textField {
    if ([_tf isEqual:textField]) {
      self.label.text = textField.text;
    }
}

- (BOOL)textField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string {
  if ([_tf isEqual:textField]) {
    self.label.text = textField.text;
  }
  return YES;
}


- (BOOL)textFieldShouldClear:(UITextField *)textField {
  return YES;
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField {
  [self.tf resignFirstResponder];
  return YES;
}

@end
