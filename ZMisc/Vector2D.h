
#define  MIN_DOUBLE 0.0000000001
class Vector2D
{
public:
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
    inline double Sign(const Vector2D& v2)const;

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
        x *= rhs;
        y *= rhs;
        return *this;
    }

    const Vector2D& operator /= (const Vector2D &rhs)
    {
        x /= rhs;
        y /= rhs;
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

private:
    double x;
    double y;
};

inline Vector2D operator*(const Vector2D &lhs, double rhs);
inline Vector2D operator*(double lhs, const Vector2D &rhs);
inline Vector2D operator-(const Vector2D &lhs, const Vector2D &rhs);
inline Vector2D operator+(const Vector2D &lhs, const Vector2D &rhs);
inline Vector2D operator/(double lhs, const Vector2D &rhs);
