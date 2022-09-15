Pod::Spec.new do |s|
    s.name         = "GSWallet"
    s.version      = "1.2.2"
    s.summary      = "Used to integrate the Game Space Platform with your iOS apps. Learn more at https://game.space."
    s.homepage     = "https://game.space"
    s.license      = {
        :type => 'Commercial',
        :text => <<-LICENSE
                  Copyright (C) 2022 Game Space.
                  Permission is hereby granted to use this framework as is, modification are not allowed.
                  All rights reserved.
          
          THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
          IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
          FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
          AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
          LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
          OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
          THE SOFTWARE.
        LICENSE
      }
    s.author              = { "Game Space" => "developer@game.space" }
    s.platform            = :ios, '9.0'
    s.source              = { :git => "https://github.com/gamespacegaas/gamespace-ios-sdk.git", :tag => s.version.to_s }
    s.source_files        = 'GSWallet.framework/Versions/A/Headers/*.h'
    s.vendored_frameworks = 'GSWallet.framework'
    s.frameworks          = 'UIKit', 'CFNetwork'
    s.xcconfig            = { 'FRAMEWORK_SEARCH_PATHS' => '"$(PODS_ROOT)/GSWallet/"' }
    s.requires_arc        = true
    s.pod_target_xcconfig  = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
    s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  end
  
