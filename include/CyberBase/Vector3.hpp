#ifndef CYBERBASE_VECTOR3_HPP
#define CYBERBASE_VECTOR3_HPP

namespace cb
{

/**
 *  3D vector
 */
class Vector3
{
  public:
    /**
     * Default constructor.
     */
    Vector3() = default;

    /**
     * Constructor.
     */
    Vector3(float p_x, float p_y, float p_z);

    /**
     * getter for x
     */
    float x() const;

    /**
     * getter for y
     */
    float y() const;

    /**
     * getter for z
     */
    float z() const;

  private:
    float m_x = 0.f;
    float m_y = 0.f;
    float m_z = 0.f;
};

} // namespace cb

#endif // CYBERBASE_VECTOR3_HPP