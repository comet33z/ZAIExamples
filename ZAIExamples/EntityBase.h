#ifndef ENTITY_BASE_H
#define ENTITY_BASE_H


class CEntityBase
{
public:
    enum 
    {
        E_ENTITY_TYPE_DEFAULT = -1,
    };

private:

    int m_nID;

    int m_nEntityType;

    bool m_bTag;

    int NextValidID() { static int NextID = 0; return NextID++; }

protected:
    Vector2D m_vPos;
    Vector2D m_vScale;

     //the length of this object's bounding radius
    double m_dBoundingRadius;

    CEntityBase() : m_nID(NextValidID()),
                    m_dBoundingRadius(0.0),
                    m_vPos(Vector2D()),
                    m_vScale(Vector2D(1.0, 1.0)),
                    m_nEntityType(E_ENTITY_TYPE_DEFAULT),
                    m_bTag(false)
    {
    }

    CEntityBase(int entity_type) : m_nID(NextValidID()),
        m_dBoundingRadius(0.0),
        m_vPos(Vector2D()),
        m_vScale(Vector2D(1.0, 1.0)),
        m_nEntityType(entity_type),
        m_bTag(false)
    {
    }

    CEntityBase(int entity_type, Vector2D pos, double r) : m_nID(NextValidID()),
        m_dBoundingRadius(r),
        m_vPos(pos),
        m_vScale(Vector2D(1.0, 1.0)),
        m_nEntityType(entity_type),
        m_bTag(false)
    {
    }

    CEntityBase(int entity_type, int forced_id ) : m_nID(forced_id),
        m_dBoundingRadius(0.0),
        m_vPos(Vector2D()),
        m_vScale(Vector2D(1.0, 1.0)),
        m_nEntityType(entity_type),
        m_bTag(false)
    {
    }

public:
    virtual ~CEntityBase() {}
    virtual void Update(double time_elapsed){};
    virtual void Render(){};
    virtual void HandleMessage(const Telegram& msg){ return false; }
    virtual void Write(std::ostream& os)const{}
    virtual void Read(std::ifstream& is){}

    Vector2D Pos()const{return m_vPos;}
    void SetPos(Vector2D new_pos){ m_vPos = new_pos; }

    double BRadius()const { return m_dBoundingRadius; }
    void SetBRadius(double r){ m_dBoundingRadius = r; }
    int ID()const { return m_nID; }

    bool IsTagged()const { return m_bTag; }
    void Tag() { m_bTag = true; }
    void UnTag() { m_bTag = false; }

    Vector2D Scale()const { return m_vScale; };

    int EntityType()const { return m_nEntityType; }
    void SetEntityType(int new_type) { m_nEntityType = new_type; }
};

#endif