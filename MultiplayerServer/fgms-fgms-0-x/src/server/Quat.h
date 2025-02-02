#if !defined QUAT_HXX
#define QUAT_HXX

//utility-class
//provides function to calculate orientation with the help of quaternionen

#include "fg_geometry.hxx"
#include <math.h>
#include <flightgear/MultiPlayer/mpmessages.hxx>

class Quat
	{

	public:
		//default constructor
		Quat(void);
		//constructor, initialize by the given values
		Quat(double x, double y, double z, double w)
			{
			m_x = x;
			m_y = y;
			m_z = z;
			m_w = w;
			}

		//default destructor
		~Quat(void);

		//initialize with zeros
		Quat zeros(void)
			{
			m_x = 0;
			m_y = 0;
			m_z = 0;
			m_w = 0;
			}
		/// Create a quaternion from the angle axis representation where the angle
		/// is stored in the axis' length
		static Quat fromAngleAxis(const Point3D& axis);

		/// Return a quaternion from real and imaginary part
		static Quat fromRealImag(double r, Point3D& i);

		/// Return the conjugate quaternion
		static Quat conjugate(Quat q);

		/// write the euler angles into the references
		void getEulerRad(double& zRad, double& yRad, double& xRad) const;

		/// Return a quaternion from euler angles which describes the transformation from global to local
		static Quat Quat::fromEulerRad(double phi, double theta, double psi);
		
		/// Return a AngleAxis from Quat
		static Point3D Quat::getAngleAxis(Quat q);

		///Return Hamilton-Product   of trwo quaternions
		static Quat hamiltonProd(Quat q, Quat e );

		static Quat InitQuat(T_PositionMsg* PosMsg);
		
		double getX();
		double getY();
		double getZ();
		double getW();

	private:
		void Quat::normalise();

		//x-part of the imaginary-part of the quaternion
		double m_x;
		//y-part of the imaginary-part of the quaternion
		double m_y;
		//z-part of the imaginary-part of the quaternion
		double m_z;
		//real part of the quaternion
		double m_w;
	};
#endif