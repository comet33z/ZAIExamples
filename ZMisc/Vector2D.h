#ifndef VECTOR2D_H_
#define  VECTOR2D_H_
#define  MIN_DOUBLE 0.0000000001

class Vector2D
{
public:
    double x;
    double y;

    Vector2D():x(0.0), y(0.0){}
    Vector2D(double a, double b):x(a), y(b){}

    void Zero(){ x = 0.0; y = 0.0; }

    bool IsZero()const {return (x*x + y*y) < MIN_DOUBLE; }

    inline double Length()const;

    inline double LengthSq()const;

    inline void Normalize();

    inline double Dot(const Vector2D& v2)const;

    //returns positive if v2 is clockwise of this vector,
    //negative if anticlockwise (assuming the Y axis is pointing down,
    //X axis to right like a Window app)
    inline int Sign(const Vector2D& v2)const;

    //returns the vector that is perpendicular to this one.
    inline Vector2D Perp()const;

    //adjusts x and y so that the length of the vector does not exceed max
    inline void Truncate(double max);

    inline double Distance(const Vector2D &v2)const;

    inline double DistanceSq(const Vector2D &v2)const;

    inline void Reflect(const Vector2D &norm);

    inline Vector2D GetReverse()const;

    const Vector2D& operator += (const Vector2D &rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    const Vector2D& operator -= (const Vector2D &rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }

    const Vector2D& operator *= (const Vector2D &rhs)
    {
        x *= rhs.x;
        y *= rhs.y;
        return *this;
    }

    const Vector2D& operator /= (const Vector2D &rhs)
    {
        x /= rhs.x;
        y /= rhs.y;
        return *this;
    }
    
    bool operator == (const Vector2D &rhs)const
    {

        return (isEqual(x, rhs.x) && isEqual(y, rhs.y)) ;
    }

    bool operator != (const Vector2D &rhs) const
    {
        return (x != rhs.x) || (y != rhs.y);
    }


};

inline Vector2D operator*(const Vector2D &lhs, double rhs);
inline Vector2D operator*(double lhs, const Vector2D &rhs);
inline Vector2D operator-(const Vector2D &lhs, const Vector2D &rhs);
inline Vector2D operator+(const Vector2D &lhs, const Vector2D &rhs);
inline Vector2D operator/(double lhs, const Vector2D &rhs);
std::ostream& operator<<(std::ostream& os, const Vector2D& rhs);
std::ifstream& operator>>(std::ifstream& is, Vector2D& lhs);

inline double Vector2D::Length()const
{
    return sqrt(x*x + y*y);
}

inline double Vector2D::LengthSq()const
{
    return  (x*x + y*y);
}

inline double Vector2D::Dot(const Vector2D &v2)const
{
    return x*v2.x + y*v2.y;
}

enum 
{ 
    E_CLOCK_WISE = 1,
    E_ANTI_CLOCK_WISE = -1
};

inline int Vector2D::Sign(const Vector2D& v2)const
{
    if ( y*v2.x > x*v2.y )
    {
        return E_ANTI_CLOCK_WISE;
    }
    else
    {
        return E_CLOCK_WISE;
    }
}

inline Vector2D Vector2D::Perp()const
{
    return Vector2D(-y, x);
}

inline double Vector2D::Distance(const Vector2D &v2)const
{
    double ySeparation = v2.y - y;
    double xSeparation = v2.x - x;

    return sqrt(ySeparation*ySeparation + xSeparation*xSeparation);
}

inline double Vector2D::DistanceSq(const Vector2D &v2)const
{
    double ySeparation = v2.y - y;
    double xSeparation = v2.x - x;

    return (ySeparation*ySeparation + xSeparation*xSeparation);
}


//----------------------------- Truncate ---------------------------------
//
//  truncates a vector so that its length does not exceed max
//------------------------------------------------------------------------
inline void Vector2D::Truncate(double max)
{
    if ( this->Length() > max )
    {
        this->Normalize();
        *this *= max;
    }
}

//--------------------------- Reflect ------------------------------------
//
//  given a normalized vector this method reflects the vector it
//  is operating upon. (like the path of a ball bouncing off a wall)
//------------------------------------------------------------------------
inline void Vector2D::Reflect(const Vector2D& norm)
{
    *this += 2.0 * this->Dot(norm) * norm.GetReverse();
}

inline Vector2D Vector2D::GetReverse()const
{
    return Vector2D(-this->x, -this->y);
};

inline void Vector2D::Normalize()
{
    double vLength = this->Length();
    if ( vLength > std::numeric_limits<double>::epsilon() )
    {
        this->x /= vLength;
        this->y /= vLength;
    }
}

//------------------------------------------------------------------------non member functions
inline Vector2D Vec2DNormalize(const Vector2D &v)
{
    Vector2D vec = v;
    double vLength = vec.Length();
    if ( vLength > std::numeric_limits<double>::epsilon() )
    {
        vec.x /= vLength;
        vec.y /= vLength;
    }

    return vec;
}

inline double Vec2DDistance(const Vector2D &v1, const Vector2D &v2)
{
    double ySeparation = v2.y - v1.y;
    double xSeparation = v2.x - v1.x;
    
    return ySeparation*ySeparation + xSeparation*xSeparation;
}

inline double Vec2DDistanceSq(const Vector2D &v1, const Vector2D &v2)
{

    double ySeparation = v2.y - v1.y;
    double xSeparation = v2.x - v1.x;

    return ySeparation*ySeparation + xSeparation*xSeparation;
}

inline double Vec2DLength(const Vector2D& v)
{
    return sqrt(v.x*v.x + v.y*v.y);
}

inline double Vec2DLengthSq(const Vector2D& v)
{
    return (v.x*v.x + v.y*v.y);
}

inline Vector2D POINTStoVector(const POINTS& P)
{
   return Vector2D(p.x, p.y);
}

inline Vector2D POINTtoVector(const POINT& p)
{
    return Vector2D((double)p.x, (double)p.y);
}

inline POINTS VectorToPOINTS(const Vector2D& v)
{
    POINTS p;
    p.x = (short)v.x;
    p.y = (short)v.y;

    return p;
}

inline POINT VectorToPOINT(const Vector2D& v)
{
    POINT p;
    p.x = (long)v.x;
    p.y = (long)v.y;

    return p;
}




#endif // !1