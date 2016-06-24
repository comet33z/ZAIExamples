#ifndef MOVING_ENTITY_H
#define MOVING_ENTITY_H

#include "EntityBase.h"
#include "Vector2D.h"

class CMovingEntity : public CEntityBase
{
protected:
    Vector2D m_vVelocity;
    Vector2D m_vHeading;
    Vector2D m_vSide;

    double m_dMass;
    double m_dMaxSpeed;
    double m_dMaxForce;
    double m_dMaxTurnRate;

public:

    CMovingEntity(Vector2D position,
                  double radius,
                  Vector2D velocity,
                  double max_speed,
                  Vector2D heading, 
                  double mass,
                  Vector2D scale,
                  double turn_rate,
                  double max_force):CEntityBase(0, position, radius),
                                    m_vHeading(heading),
                                    m_vVelocity(velocity),
                                    m_dMass(mass),
                                    m_vSide(m_vVelocity.Perp()),
                                    m_dMaxSpeed(max_speed),
                                    m_dMaxTurnRate(turn_rate),
                                    m_dMaxForce(max_force)

    {
        m_vScale = scale;
    }

    virtual ~CMovingEntity(){}

    Vector2D Velocity()const { return m_vVelocity; }
    void SetVelocity( const Vector2D& newVel ) { m_vVelocity = newVel; }


};


#endif