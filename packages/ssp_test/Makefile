include $(TOPDIR)/rules.mk

PKG_NAME:=ssp_test
PKG_VERSION:=master
PKG_RELEASE:=1

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)

# NOTE: Must disable global -Os
# Ok to stomp globals for my purposes
TARGET_CFLAGS = -pipe -mips32r2 -mtune=mips32r2 -fno-caller-saves -ggdb3 -O0 -fstack-protector-all --param=ssp-buffer-size=4
TARGET_LDFLAGS += -lssp

include $(INCLUDE_DIR)/package.mk

define Package/$(PKG_NAME)
	SECTION:=commotion
	CATEGORY:=Commotion
	SUBMENU:=Utilities
	DEPENDS:=+commotion +gdbserver +SSP_SUPPORT:libssp
	TITLE:=SSP Test
	URL:=https://commotionwireless.net/
endef

define Package/$(PKG_NAME)/description
	Simple buffer overflow to test new ssp option in commotion-router
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Package/$(PKG_NAME)/install
	$(INSTALL_DIR) $(1)/root
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/smash $(1)/root
endef

$(eval $(call BuildPackage,ssp_test))

