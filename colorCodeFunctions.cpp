#include <iostream>
#include <assert.h> 
#include <sstream>
#include "colorCodeDefinitions.h"
void testNumberToPair(int pairNumber,
    TelCoColorCoder::MajorColor expectedMajor,
    TelCoColorCoder::MinorColor expectedMinor)
{
    TelCoColorCoder::ColorPair colorPair =
        TelCoColorCoder::GetColorFromPairNumber(pairNumber);
    std::cout << "Got pair " << colorPair.ToString() << std::endl;
    assert(colorPair.getMajor() == expectedMajor);
    assert(colorPair.getMinor() == expectedMinor);
}
void testPairToNumber(
    TelCoColorCoder::MajorColor major,
    TelCoColorCoder::MinorColor minor,
    int expectedPairNumber)
{
    int pairNumber = TelCoColorCoder::GetPairNumberFromColor(major, minor);
    std::cout << "Got pair number " << pairNumber << std::endl;
    assert(pairNumber == expectedPairNumber);
}
std::string ToString()
{
    std::cout <<std::endl <<"Number to Color Mapping"<<std::endl<<std::endl;
    std::string mapping=""; // Big string storing entire mapping
    //Computing the loop limit number below
    int pairLimit= TelCoColorCoder::GetPairNumberFromColor(TelCoColorCoder::VIOLET,TelCoColorCoder::SLATE);
    for (int pairNumber=1;pairNumber<=pairLimit;pairNumber++)
    {
        TelCoColorCoder::ColorPair colorPair =
            TelCoColorCoder::GetColorFromPairNumber(pairNumber);
         mapping += std::to_string(pairNumber)+"-->"+colorPair.ToString()+"\n";
    }
    return mapping;
}
int main() {
    testNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
    testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);

    testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
    testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);

    //Printing  color to number mapping
    std::cout<<ToString();
    return 0;
}