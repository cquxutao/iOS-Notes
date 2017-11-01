//
//  CustomDogViewModel.h
//  CustomViewDemo
//
//  Created by 徐涛 on 07/08/2017.
//  Copyright © 2017 徐涛. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CustomDogViewModel : NSObject

@property (nonatomic,copy) NSString *name;
@property (nonatomic,copy) NSString *pic;

+ (instancetype) modelWithName:(NSString *)name andPic:(NSString *)pic;

@end
