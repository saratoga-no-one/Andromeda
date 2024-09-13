#ifndef ANDROMEDA_GRAPHICS_RENDERABLEMODEL
#define ANDROMEDA_GRAPHICS_RENDERABLEMODEL

#include <vector>
#include "Renderable.hpp"

#include "../../lib/assimp/postprocess.h"

namespace andromeda {
	namespace graphics {
		//等同于Model，由多个Renderable对象组成的模型
		class RenderableModel
		{
		private:
			const char* model_path=nullptr;
		public:
			std::vector<Renderable> renderable_list;//渲染对象列表，将从索引0开始依次渲染

			RenderableModel()=default;

			inline const char* getModelPath()
			{
				return  model_path;
			}

			/*attrib_order为不区分大小写的字符串，每个字符代表一种属性。V顶点，N法线，G顶点tangents，I顶点bittangents，C颜色，T纹理坐标，如果不存在该属性，则忽略
			 * 不同属性以','隔开，部分属性名称(C、T)后可选加数字，例如T0表示索引0的纹理坐标，T1表示索引1的纹理坐标，不加数字默认为索引0，加了但不存在该索引则忽略该索引。
			 * texture_types为要加载的纹理贴图类型，详细种类缩写见Texture2D.cpp中的parseTextureType()
			*/
			static RenderableModel* loadModel(const char* model_path,const char* attrib_order="V,N,T",const char *texture_types="Co,Sp",int post_process=aiProcess_Triangulate|aiProcess_FlipUVs);
		};
	}
}

#endif//ANDROMEDA_GRAPHICS_RENDERABLEMODEL
