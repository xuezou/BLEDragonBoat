//
//  BLESolstice.h
//  BLESolstice
//
//  Created by A$CE on 2017/10/9.
//  Copyright © 2017年 A$CE. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "BLEQuinox.h"

@class ZRBlePeripheral;


/**
 Communication agent, holding peripheral connection object, make a protocol conversion between the app and the device, so that the API is easier to understand than the binary.
 All api are suitable for the scene, not all devices support all api, if your device does not support your api call, you will get an NSError or in the console to see the "device does not support" log
 */
@protocol BLESolstice <NSObject,CBPeripheralDelegate>

/**
 * Get solstice instance by peripheral device.
 */
+ (id<BLESolstice>)cBLESolstice:(ZRBlePeripheral *)bleDevice;

/**
 This method can help you to get that Device object you are connected to.

 @return Returns as a CBPeripheral object
 */
- (CBPeripheral *)getConnectedPeriphral;

/*
 * Call this method if you had change the peripheral's delegate for any other object.
 */
- (void)registerDeviceDelegate;

/**
 Call this method after initinal <BLESolstice> object; or ,you can not got any data callback from SDK.
 
 @param equinox The object that implements the <BLEquinox> protocol method, accepts data from sdk
 */
- (void)registerSolsticeEquinox:(id<BLEQuinox>)equinox;

@end



