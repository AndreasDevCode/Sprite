#include "RectI.h"

RectI::RectI(int left_in, int right_in, int top_in, int bottom_in)
	:
	left(left_in),
	right(right_in),
	top(top_in),
	bottom(bottom_in)
{

}
RectI::RectI(const Vei2& topLeft, int width, int height)
{
	const int newLeft	 = topLeft.x;
	const int newRight   = newLeft + width;
	const int newTop	 = topLeft.y;
	const int newBottom	 = newTop+height;

	RectI(newLeft, newRight, newTop, newBottom);
}
RectI::RectI(const Vei2& topLeft, const Vei2& bottomRight)
{
	const int newLeft	 = topLeft.x;
	const int newRight	 = bottomRight.x;
	const int newTop	 = topLeft.y;
	const int newBottom	 = bottomRight.y;

	RectI(newLeft, newRight, newTop, newBottom);
}
bool RectI::IsOverLappingWith(const RectI& other) const
{
	return (left< other.right && right>other.left 
		&& top<other.bottom && bottom >other.top);
}
bool RectI::IsContainedBy(const RectI& other) const
{
	return left >= other.left && right <= other.right
		&& top >= other.top && bottom <= other.bottom;
}
bool RectI::Contains(const Vei2& point) const
{
	return point.x >= left && point.x <= right && point.y >= top && point.y <= bottom;
}

RectI RectI::FromCenter(const Vei2& center, int halfWidth, int halfHeight)
{
	const Vei2 half(halfWidth, halfHeight);
	return RectI(center-half, center +half);
}

RectI RectI::GetExpanded(int offset) const
{
	return RectI(left - offset, right+offset, top - offset, bottom + offset);
}

Vei2 RectI::GetCenter() const
{
	return Vei2((left+right)/2, (top+bottom)/2);
}
int RectI::GetWidth() const
{
	return right - left;
}
int RectI::GetHeight() const
{
	return bottom - top;
}