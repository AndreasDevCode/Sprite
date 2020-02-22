#pragma once
#include "Vec2.h"

class RectI
{
public:
	RectI() = default;
	RectI(int left_in, int right_in, int top_in, int bottom_in);
	RectI(const Vei2& topLeft, int width, int height);
	RectI(const Vei2& topLeft, const Vei2& bottomRight);

	bool IsOverLappingWith(const RectI& other) const;
	bool IsContainedBy(const RectI& other) const;
	bool Contains(const Vei2& point) const;

	static RectI FromCenter(const Vei2& center, int helfWidth, int halfHeight);
	RectI GetExpanded(int offset) const;
	Vei2 GetCenter() const;
public:
	int top;
	int right;
	int bottom;
	int left;
};

