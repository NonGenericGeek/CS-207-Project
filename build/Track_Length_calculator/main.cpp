//  Created by Logan Slater on 23 October 2016.

#include <iostream>
#include <cmath>

int main() {
    std::string units;
    std::cout << "\nPlease refer to the image in the Readme file in the GitHub repository at github.com/NonGenericGeek/CS-207-Project.\nPlease make sure you're measuring the distance between the axles of your frame.\nMeasurements should all be in the same units. Otherwise, the result will be wrong.\n";
    
    std::cout << "\nPlease enter the units you intend to use (e.g. millimeters, attoparsecs, beard-seconds): ";
    std::cin >> units;
    
    double height, topLength, bottomLength, frontSegment, wheelRadius, result, temp;
    std::cout << "\nPlease enter the height of your frame: ";
    std::cin >> height;
    std::cout << "\nPlease enter the Top length: ";
    std::cin >> topLength;
    std::cout << "\nPlease enter the Bottom length: ";
    std::cin >> bottomLength;
    std::cout << "\nPlease enter the length of the Top Front Segment: ";
    std::cin >> frontSegment;
    std::cout << "\nPlease enter the radius of the Wheel: ";
    std::cin >> wheelRadius;
    
    temp = (180.0 / 3.14159) * atan((sqrt(2.0) / 2.0) / (sqrt(2.0) / 2.0));
    if (temp > 44 && temp < 46) {
        temp = topLength - (bottomLength + frontSegment);
        result = topLength + bottomLength + sqrt((frontSegment * frontSegment) + (height * height)) + sqrt((temp * temp) + (height * height)) + (wheelRadius * atan(temp / height)) + (wheelRadius * atan(frontSegment / height)) + (wheelRadius * (atan(height / temp) + (3.14159 / 2.0))) + (wheelRadius * (atan(height / frontSegment) + (3.14159 / 2.0)));
    }
    else {
        std::cout << "\nYour computer does math differently than mine, so this MAY be wrong. Just letting you know.";
        temp = topLength - (bottomLength + frontSegment);
        result = topLength + bottomLength + sqrt((frontSegment * frontSegment) + (height * height)) + sqrt((temp * temp) + (height * height)) + (wheelRadius * (3.14159 / 180.0) * atan(temp / height)) + (wheelRadius * (3.14159 / 180.0) * atan(frontSegment / height)) + (wheelRadius * ((3.14159 / 180.0) * atan(height / temp) + (3.14159 / 2.0))) + (wheelRadius * ((3.14159 / 180.0) * atan(height / frontSegment) + (3.14159 / 2.0)));
    }
    
    std::cout << "\nThe track will be " << result << " " << units << " long.\n";
    if (result < 0)
        std::cout << "That doesn't seem right, but I won't judge.\n;";
    return 0;
}
