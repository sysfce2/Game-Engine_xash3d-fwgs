"#if VER <= 300\n"
"#define layout(x)\n"
"#endif\n"
"#if VER < 300\n"
"#define out attribute\n"
"#define in varying\n"
"#define texture texture2D\n"
"#endif\n"
"#if VER >= 130 || VER == 100\n"
"precision mediump float;\n"
"#endif\n"
"#if VER == 100\n"
"#define PREC mediump\n"
"#else\n"
"#define PREC\n"
"#endif\n"
"#if ATTR_TEXCOORD0\n"
"uniform sampler2D uTex0;\n"
"#endif\n"
"#if ATTR_TEXCOORD1\n"
"uniform sampler2D uTex1;\n"
"#endif\n"
"#if FEAT_ALPHA_TEST\n"
"uniform float uAlphaTest;\n"
"#endif\n"
"#if FEAT_FOG\n"
"uniform PREC vec4 uFog;\n"
"#endif\n"
"uniform PREC vec4 uColor;\n"
"#if ATTR_COLOR\n"
"in PREC vec4 vColor;\n"
"#endif\n"
"#if ATTR_TEXCOORD0\n"
"in PREC vec2 vTexCoord0;\n"
"#endif\n"
"#if ATTR_TEXCOORD1\n"
"in PREC vec2 vTexCoord1;\n"
"#endif\n"
"#if ATTR_NORMAL\n"
"in PREC vec2 vNormal;\n"
"#endif\n"
"#if VER >= 300\n"
"out vec4 oFragColor;\n"
"#else\n"
"#define oFragColor gl_FragColor\n"
"#endif\n"
"void main()\n"
"{\n"
"#if ATTR_COLOR\n"
"PREC vec4 c = vColor;\n"
"#else\n"
"PREC vec4 c = uColor;\n"
"#endif\n"
"#if ATTR_TEXCOORD0\n"
"c = c * texture(uTex0, vTexCoord0);\n"
"#endif\n"
"#if ATTR_TEXCOORD1\n"
"c = c * texture(uTex1, vTexCoord1);\n"
"#endif\n"
"#if FEAT_ALPHA_TEST\n"
"if(c.a <= uAlphaTest)\n"
"discard;\n"
"#endif\n"
"#if FEAT_FOG\n"
"float fogDist = gl_FragCoord.z / gl_FragCoord.w;\n"
"float fogRate = clamp(exp(-uFog.w * fogDist), 0.0, 1.0);\n"
"c.rgb = mix(uFog.rgb, c.rgb, fogRate);\n"
"#endif\n"
"oFragColor = c;\n"
"}\n"