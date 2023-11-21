#!/bin/bash

~/generator/core-generator/commonapi-core-generator-linux-x86_64 --skel --dest-common ./src-gen/CANSender/core/common --dest-proxy ./src-gen/CANSender/core/proxy --dest-stub ./src-gen/CANSender/core/stub --dest-skel ./src-gen/CANSender/core/skel ./fidl/CANSender/CANSender.fidl

~/generator/someip-generator/commonapi-someip-generator-linux-x86_64 --dest-common ./src-gen/CANSender/someip/common --dest-proxy ./src-gen/CANSender/someip/proxy --dest-stub ./src-gen/CANSender/someip/stub ./fidl/CANSender/CANSender.fdepl


~/generator/core-generator/commonapi-core-generator-linux-x86_64 --skel --dest-common ./src-gen/PiracerSender/core/common --dest-proxy ./src-gen/PiracerSender/core/proxy --dest-stub ./src-gen/PiracerSender/core/stub --dest-skel ./src-gen/PiracerSender/core/skel ./fidl/PiracerSender/PiracerSender.fidl

~/generator/someip-generator/commonapi-someip-generator-linux-x86_64 --dest-common ./src-gen/PiracerSender/someip/common --dest-proxy ./src-gen/PiracerSender/someip/proxy --dest-stub ./src-gen/PiracerSender/someip/stub ./fidl/PiracerSender/PiracerSender.fdepl


~/generator/core-generator/commonapi-core-generator-linux-x86_64 --skel --dest-common ./src-gen/PiracerController/core/common --dest-proxy ./src-gen/PiracerController/core/proxy --dest-stub ./src-gen/PiracerController/core/stub --dest-skel ./src-gen/PiracerController/core/skel ./fidl/PiracerController/PiracerController.fidl

~/generator/someip-generator/commonapi-someip-generator-linux-x86_64 --dest-common ./src-gen/PiracerController/someip/common --dest-proxy ./src-gen/PiracerController/someip/proxy --dest-stub ./src-gen/PiracerController/someip/stub ./fidl/PiracerController/PiracerController.fdepl


~/generator/core-generator/commonapi-core-generator-linux-x86_64 --skel --dest-common ./src-gen/IPCManager/core/common --dest-proxy ./src-gen/IPCManager/core/proxy --dest-stub ./src-gen/IPCManager/core/stub --dest-skel ./src-gen/IPCManager/core/skel ./fidl/IPCManager/IPCManager.fidl

~/generator/someip-generator/commonapi-someip-generator-linux-x86_64 --dest-common ./src-gen/IPCManager/someip/common --dest-proxy ./src-gen/IPCManager/someip/proxy --dest-stub ./src-gen/IPCManager/someip/stub ./fidl/IPCManager/IPCManager.fdepl


~/generator/core-generator/commonapi-core-generator-linux-x86_64 --skel --dest-common ./src-gen/InstrumentCluster/core/common --dest-proxy ./src-gen/InstrumentCluster/core/proxy --dest-stub ./src-gen/InstrumentCluster/core/stub --dest-skel ./src-gen/InstrumentCluster/core/skel ./fidl/InstrumentCluster/InstrumentCluster.fidl

~/generator/someip-generator/commonapi-someip-generator-linux-x86_64 --dest-common ./src-gen/InstrumentCluster/someip/common --dest-proxy ./src-gen/InstrumentCluster/someip/proxy --dest-stub ./src-gen/InstrumentCluster/someip/stub ./fidl/InstrumentCluster/InstrumentCluster.fdepl


~/generator/core-generator/commonapi-core-generator-linux-x86_64 --skel --dest-common ./src-gen/HeadUnit/core/common --dest-proxy ./src-gen/HeadUnit/core/proxy --dest-stub ./src-gen/HeadUnit/core/stub --dest-skel ./src-gen/HeadUnit/core/skel ./fidl/HeadUnit/HeadUnit.fidl

~/generator/someip-generator/commonapi-someip-generator-linux-x86_64 --dest-common ./src-gen/HeadUnit/someip/common --dest-proxy ./src-gen/HeadUnit/someip/proxy --dest-stub ./src-gen/HeadUnit/someip/stub ./fidl/HeadUnit/HeadUnit.fdepl


~/generator/core-generator/commonapi-core-generator-linux-x86_64 --skel --dest-common ./src-gen/PDCUnit/core/common --dest-proxy ./src-gen/PDCUnit/core/proxy --dest-stub ./src-gen/PDCUnit/core/stub --dest-skel ./src-gen/PDCUnit/core/skel ./fidl/PDCUnit/PDCUnit.fidl

~/generator/someip-generator/commonapi-someip-generator-linux-x86_64 --dest-common ./src-gen/PDCUnit/someip/common --dest-proxy ./src-gen/PDCUnit/someip/proxy --dest-stub ./src-gen/PDCUnit/someip/stub ./fidl/PDCUnit/PDCUnit.fdepl


~/generator/core-generator/commonapi-core-generator-linux-x86_64 --skel --dest-common ./src-gen/IVICompositor/core/common --dest-proxy ./src-gen/IVICompositor/core/proxy --dest-stub ./src-gen/IVICompositor/core/stub --dest-skel ./src-gen/IVICompositor/core/skel ./fidl/IVICompositor/IVICompositor.fidl

~/generator/someip-generator/commonapi-someip-generator-linux-x86_64 --dest-common ./src-gen/IVICompositor/someip/common --dest-proxy ./src-gen/IVICompositor/someip/proxy --dest-stub ./src-gen/IVICompositor/someip/stub ./fidl/IVICompositor/IVICompositor.fdepl


~/generator/core-generator/commonapi-core-generator-linux-x86_64 --skel --dest-common ./src-gen/RemoteSpeaker/core/common --dest-proxy ./src-gen/RemoteSpeaker/core/proxy --dest-stub ./src-gen/RemoteSpeaker/core/stub --dest-skel ./src-gen/RemoteSpeaker/core/skel ./fidl/RemoteSpeaker/RemoteSpeaker.fidl

~/generator/someip-generator/commonapi-someip-generator-linux-x86_64 --dest-common ./src-gen/RemoteSpeaker/someip/common --dest-proxy ./src-gen/RemoteSpeaker/someip/proxy --dest-stub ./src-gen/RemoteSpeaker/someip/stub ./fidl/RemoteSpeaker/RemoteSpeaker.fdepl

