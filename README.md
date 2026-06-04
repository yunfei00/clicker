# clicker

手机自动点击器固件工程。

## 项目信息

- **项目名称**：clicker / `stc15f104Test`
- **芯片型号**：STC15F104E
- **工程类型**：Keil C51 / Keil µVision MCS-51 工程
- **工程文件**：`stc15f104Test/stc15f104Test.uvproj`

`stc15f104Test` 目录包含 Keil C51 工程文件、STC15F104E 头文件、启动文件和业务源码。当前工程使用 Keil C51 语法和 µVision 工程配置；GitHub Actions 会尝试使用 SDCC 编译 8051 程序，但如果源码无法被 SDCC 直接编译，CI 仍会打包源码并上传构建产物。完整固件构建以 Keil C51 为准。

## 本地使用 Keil 打开

1. 安装 Keil µVision 和 C51 工具链。
2. 打开 Keil µVision。
3. 选择 **Project → Open Project...**。
4. 打开 `stc15f104Test/stc15f104Test.uvproj`。
5. 在 Keil 中选择目标 `Target 1`，执行 **Build**。
6. 工程配置已启用 Hex 生成，构建成功后可得到 Keil 生成的 HEX 固件文件。

## GitHub Actions 构建产物

仓库包含 GitHub Actions workflow：`.github/workflows/build.yml`。

- push 到 `main` 分支时会自动运行构建。
- push `v*` tag（例如 `v1.0.0`）时会自动运行构建并发布 GitHub Release。
- CI 会始终生成并上传：
  - `stc15f104Test-source.zip`：源码压缩包
  - `build-info.txt`：构建环境、提交和 SDCC 编译结果说明
- 如果 SDCC 编译成功，CI 还会生成并上传：
  - `firmware.hex`

下载方式：

1. 打开 GitHub 仓库页面。
2. 进入 **Actions**。
3. 选择最近一次 workflow 运行。
4. 在页面底部 **Artifacts** 区域下载 `stc15f104Test-build`。
5. 如果是 `v*` tag 触发的构建，也可以在仓库 **Releases** 页面下载 Release 资产。
