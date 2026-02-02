#pragma once

#pragma pack (push, 8)

//for AcadAcCmColor
std::string rgbToHex(int r, int g, int b);
std::tuple<int, int, int> hexToRGB(const std::string& hexString);

void makePyCmColorWrapper();
void makePyCmTransparencyWrapper();
void makePyCmEntityColorWrapper();

#pragma pack (pop)
