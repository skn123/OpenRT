#include "BRDFPhong.h"

rt::CBRDFPhong::CBRDFPhong(float ke) 
	: CBxDF(BxDFType::specular, 0)
	, m_ke(ke)
{}

float rt::CBRDFPhong::f(const Vec3f& wo, const Vec3f& wi) const 
{
	const Vec3f reflected(-wo[0], -wo[1], wo[2]);
	float cosLightReflect = std::max(0.0f, reflected.dot(wi));
	float specular = std::powf(cosLightReflect, m_ke);
	
	return specular;
}
