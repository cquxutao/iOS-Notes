//
//  CustomDogViewModel.m
//  CustomViewDemo
//
//  Created by 徐涛 on 07/08/2017.
//  Copyright © 2017 徐涛. All rights reserved.
//

#import "CustomDogViewModel.h"

@interface CustomDogViewModel ()


- (instancetype) initWithName:(NSString *)name andPic:(NSString *)pic;

@end

@implementation CustomDogViewModel

+ (instancetype) modelWithName:(NSString *)name andPic:(NSString *)pic {
    return [[self alloc] initWithName:name andPic:pic];
}

- (instancetype) initWithName:(NSString *)name andPic:(NSString *)pic {
    if (self = [super init]) {
        self.name = name;
        self.pic = pic;
    }
    return self;
}
@end
