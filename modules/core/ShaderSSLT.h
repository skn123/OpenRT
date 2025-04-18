#pragma once

#include "ShaderScene.h"

namespace rt {
	class CScene;
	// ================================ Flat Shader Class ================================
	/**
	 * @brief Sub-surface light transport shader class
	 * @ingroup moduleShader
	 * @author Ezana T. Geressu, E.Geressu@jacobs-university.de
	 */
	class CShaderSSLT : public CShaderScene {
	public:
		/**
		 * @brief Constructor
		 * @param scene The reference to the scene
		 * @param color The color of the material
		 * @param opacity The opacity of the material
		 */
		DllExport CShaderSSLT(const CScene& scene, const Vec3f& color, ptr_sampler_t pSampler = nullptr, float opacity = 1.0f)
			: CShaderScene(scene, color, pSampler)
		{ setOpacity(opacity); }


		DllExport Vec3f shade(const Ray& ray) const override;
	};
};
