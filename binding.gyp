{
    "targets": [
        {
            "target_name": "game",
            "cflags!": ["-fno-exceptions"],
            "cflags_cc!": ["-fno-exceptions"],
            "sources": ["gamew.cc"],
            "include_dirs": [
                "<(module_root_dir)/game",
                "<!@(node -p \"require('node-addon-api').include\")"
            ],
            'defines': ['NAPI_DISABLE_CPP_EXCEPTIONS'],
            'libraries': ["<(module_root_dir)/game/libgame.a"],
        }
    ]
}
